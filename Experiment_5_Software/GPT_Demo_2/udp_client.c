// udp_client.c
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define PORT 55000
#define NUM_MSG 1000

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char *message = "Performance Test Message";
    char buffer[1024];

    struct timeval start, end;
    double total_rtt = 0;
    int received = 0;

    socklen_t len = sizeof(server_addr);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    // Set timeout (IMPORTANT for packet loss)
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    for (int i = 0; i < NUM_MSG; i++) {
        gettimeofday(&start, NULL);

        sendto(sockfd, message, strlen(message), 0,
            (struct sockaddr *)&server_addr, len);

        int n = recvfrom(sockfd, buffer, sizeof(buffer), 0,
                        (struct sockaddr *)&server_addr, &len);

        gettimeofday(&end, NULL);

        if (n > 0) {
            buffer[n] = '\0';  // null terminate

            if (strcmp(buffer, message) == 0) {
                printf("Performance Test Message %d\n", i + 1);
            } else {
                printf("Mismatch at message %d\n", i + 1);
            }

            double rtt = (end.tv_sec - start.tv_sec) * 1000.0 +
                        (end.tv_usec - start.tv_usec) / 1000.0;

            total_rtt += rtt;
            received++;
        } else {
            // Packet loss case
            printf("Packet lost at message %d\n", i + 1);
        }   
    }

    printf("UDP Average RTT = %.3f ms\n", total_rtt / received);
    printf("UDP Packet Loss = %d\n", NUM_MSG - received);

    close(sockfd);
    return 0;
}