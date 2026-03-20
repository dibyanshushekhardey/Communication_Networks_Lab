// client_sched.c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>
#include <signal.h>

#define PORT 55000

typedef struct {
    int client_id;
    int job_id;
    int processing_time;
    int priority;
} Job;

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Usage: %s <client_id>\n", argv[0]);
        return 1;
    }

    signal(SIGPIPE, SIG_IGN); // prevent crash

    int client_id = atoi(argv[1]);
    srand(time(NULL) + client_id);

    for (int i = 0; i < 3; i++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);

        struct sockaddr_in serv_addr;
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(PORT);
        inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);

        if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
            perror("Connection failed");
            continue;
        }

        Job j;
        j.client_id = client_id;
        j.job_id = i + 1;
        j.processing_time = rand() % 5 + 1;
        j.priority = rand() % 5 + 1;

        if (write(sock, &j, sizeof(j)) < 0) {
            perror("Write failed");
        }

        printf("Client %d sent Job %d (P=%d, T=%d)\n",
               j.client_id, j.job_id, j.priority, j.processing_time);

        close(sock);
        sleep(1);
    }

    return 0;
}