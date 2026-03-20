// server_sched.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <sys/time.h>
#include <string.h>

#define PORT 55000
#define MAX_JOBS 100

typedef struct {
    int client_id;
    int job_id;
    int processing_time;
    int priority;
    struct timeval arrival_time;
} Job;

Job queue[MAX_JOBS];
int job_count = 0;

pthread_mutex_t lock;

// 0 = FCFS, 1 = PRIORITY
int SCHED_POLICY = 0;

// Add job safely
void enqueue(Job j) {
    pthread_mutex_lock(&lock);
    queue[job_count++] = j;
    pthread_mutex_unlock(&lock);
}

// Select next job
int get_next_job() {
    if (job_count == 0) return -1;

    int idx = 0;

    if (SCHED_POLICY == 1) {
        for (int i = 1; i < job_count; i++) {
            if (queue[i].priority > queue[idx].priority)
                idx = i;
        }
    }
    return idx;
}

// Remove job
void remove_job(int idx) {
    for (int i = idx; i < job_count - 1; i++)
        queue[i] = queue[i + 1];
    job_count--;
}

// Worker thread → continuously processes jobs
void* scheduler(void* arg) {
    while (1) {
        pthread_mutex_lock(&lock);

        int idx = get_next_job();
        if (idx == -1) {
            pthread_mutex_unlock(&lock);
            usleep(100000); // wait if no job
            continue;
        }

        Job current = queue[idx];
        remove_job(idx);

        pthread_mutex_unlock(&lock);

        struct timeval start, end;
        gettimeofday(&start, NULL);

        printf("Processing C%d-J%d | P=%d | T=%d\n",
               current.client_id, current.job_id,
               current.priority, current.processing_time);

        sleep(current.processing_time);

        gettimeofday(&end, NULL);

        double waiting =
            (start.tv_sec - current.arrival_time.tv_sec) +
            (start.tv_usec - current.arrival_time.tv_usec)/1e6;

        double response =
            (end.tv_sec - current.arrival_time.tv_sec) +
            (end.tv_usec - current.arrival_time.tv_usec)/1e6;

        printf("Done C%d-J%d | Waiting=%.2f s | Response=%.2f s\n\n",
               current.client_id, current.job_id, waiting, response);
    }
}

// Client handler thread
void* handle_client(void* socket_desc) {
    int sock = *(int*)socket_desc;
    free(socket_desc);

    Job j;
    read(sock, &j, sizeof(j));

    gettimeofday(&j.arrival_time, NULL);

    printf("Received C%d-J%d | P=%d | T=%d\n",
           j.client_id, j.job_id, j.priority, j.processing_time);

    enqueue(j);

    close(sock);
    return NULL;
}

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    pthread_mutex_init(&lock, NULL);

    server_fd = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    bind(server_fd, (struct sockaddr *)&address, sizeof(address));
    listen(server_fd, 10);

    printf("Server started on port %d (%s scheduling)\n",
           PORT, SCHED_POLICY ? "PRIORITY" : "FCFS");

    // Scheduler thread
    pthread_t sched_thread;
    pthread_create(&sched_thread, NULL, scheduler, NULL);

    while (1) {
        new_socket = accept(server_fd,
                            (struct sockaddr *)&address,
                            (socklen_t*)&addrlen);

        int *new_sock = malloc(sizeof(int));
        *new_sock = new_socket;

        pthread_t tid;
        pthread_create(&tid, NULL, handle_client, new_sock);
    }
}