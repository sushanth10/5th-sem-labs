#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<fcntl.h>
#include<netinet/in.h>


int main(int argc, char const *argv[])
{
    int cs, n;
    int buffsize=1024;
    char * buffer = malloc(buffsize);
    char fname[255];
    struct sockaddr_in address;

    address.sin_family = AF_INET;
    address.sin_port = htons(15000);
    inet_pton(AF_INET ,argv[1], &address.sin_addr); //converts address in presentation format to binary number format for the interface IPv4 (AF_INET)

    cs = socket(AF_INET, SOCK_STREAM, 0); //returns file descriptor for the socket for domain IPv4 (AF_INET) and type of socket is STREAM, 0 means that the protocol is chosen automatically 
    connect(cs, (struct sockaddr *)&address, sizeof(address)); //opens a connection on socket to address mentioned (LEN of address is also defined).
    
    // details of file to be sent
    printf("Enter filename : ");
    scanf("%s", fname);

    send(cs, fname, 255, 0); //sends 255 bytes of fname to socket file descriptor, i.e., cs.

    while(recv(cs, buffer, buffsize, 0)>0){ //reads 'buffsize' bytes into 'buffer' from socket fd 'cs'
        printf("%s\n", buffer); //prints whatever is there in buffer
    }
    printf("\nEOF\n");

    return close(cs); //closes the socket connection
}
