#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/time.h>
// UDP
#define PORT 57000

int main(int argc, char const* argv[])
{
    int status, valread, client_fd;
    struct sockaddr_in serv_addr;
    char* hello = "Performance Test Message\n";
    char buffer[1024] = { 0 };
    if ((client_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary
    // form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)
        <= 0) {
        printf(
            "\nInvalid address/ Address not supported \n");
        return -1;
    }

    if ((status
         = connect(client_fd, (struct sockaddr*)&serv_addr,
                   sizeof(serv_addr)))
        < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }
  
    // subtract 1 for the null
    // terminator at the end

    struct timeval tvalBefore, tvalAfter;
    int count = 0;

    for(int i = 0; i < 1000; i++){
        gettimeofday (&tvalBefore, NULL);
        send(client_fd, hello, strlen(hello), 0);
        //printf("Hello message sent\n");
        valread = read(client_fd, buffer,
                    1024 - 1); 
        if(valread <= 0){
            printf("Connection closed or error\n");
            break;
        }

        buffer[valread] = '\0';

        printf("%s\n", buffer);
        gettimeofday (&tvalAfter, NULL);
        printf("RTT = %ld microseconds\n",
           ((tvalAfter.tv_sec - tvalBefore.tv_sec)*1000000L +
             tvalAfter.tv_usec - tvalBefore.tv_usec));
        printf("=====================\n");
        count += 1;
    }

    // closing the connected socket
    close(client_fd);
    printf("Final Count %d\n", count);
    return 0;
}