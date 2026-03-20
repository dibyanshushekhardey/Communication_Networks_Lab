// tcp_client.c
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define PORT 55000
#define NUM_MSG 1000

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char *message = "Performance Test Message";
    char buffer[1024];

    struct timeval start, end;

    double total_rtt = 0;
    int received = 0;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    for (int i = 0; i < NUM_MSG; i++) {
        gettimeofday(&start, NULL);

        // Send message
        send(sock, message, strlen(message), 0);

        // Receive echo
        int n = read(sock, buffer, sizeof(buffer));

        gettimeofday(&end, NULL);

        if (n > 0) {
            buffer[n] = '\0';

            if (strcmp(buffer, message) == 0) {
                printf("Message %d echoed correctly\n", i+1);
            } else {
                printf("Mismatch at message %d\n", i+1);
            }

            double rtt = (end.tv_sec - start.tv_sec) * 1000.0 +
                        (end.tv_usec - start.tv_usec) / 1000.0;

            total_rtt += rtt;
            received++;
        } else {
            printf("No response for message %d\n", i+1);
        }
    }

    printf("TCP Average RTT = %.3f ms\n", total_rtt / received);
    printf("TCP Packet Loss = %d\n", NUM_MSG - received);

    close(sock);
    return 0;
}