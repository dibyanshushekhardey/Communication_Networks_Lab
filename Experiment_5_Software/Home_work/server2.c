#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
// UDP
#define PORT 57000

int main()
{
    int server_fd;
    ssize_t valread;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addrlen = sizeof(client_addr);
    char buffer[1024];

    server_fd = socket(AF_INET, SOCK_DGRAM, 0);

    if(server_fd < 0){
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if(bind(server_fd,(struct sockaddr*)&server_addr,sizeof(server_addr)) < 0){
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    while(1){

        valread = recvfrom(server_fd, buffer, 1024, 0,
                           (struct sockaddr*)&client_addr, &addrlen);

        if(valread < 0)
            continue;

        buffer[valread] = '\0';

        printf("%s\n", buffer);

        sendto(server_fd, buffer, strlen(buffer), 0,
               (struct sockaddr*)&client_addr, addrlen);
    }

    close(server_fd);
}