#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<netinet/in.h>

int main(int argc, char const *argv[])
{
    int cs, ns, n, fd;
    char fname[255];
    int buffsize = 1024;
    char * buffer = malloc(buffsize);
    struct sockaddr_in address;

    address.sin_family = AF_INET;
    address.sin_port = htons(15000);
    address.sin_addr.s_addr = INADDR_ANY; //INADDR_ANY defines the self address of 127.0.0.1

    cs = socket(AF_INET, SOCK_STREAM, 0); //returns a file descriptor of the socket for interface AF_INET of type STREAM, 0 means default protocol
    bind(cs, (struct sockaddr *)&address, sizeof(address)); //gives the socket (cs) to the address(address) of LEN bytes long.
    listen(cs, 3); //prepares to accept N(here, 3) connections at socket (cs) which are queued after which they are refused.
    ns = accept(cs, (struct sockaddr *)NULL, NULL); //awaits a connection and creates a new socket when a connection arrives at the socket and returns that socket fd (ns).
    recv(ns, fname, 255, 0); // reads 255 bytes of data from socket ns into fname
    fd = open(fname, O_RDONLY); //opens the file fname in READONLY mode
    n = read(fd, buffer, buffsize); //reads 'buffsize' bytes of data into "buffer" from file descriptor "fd"
    send(ns, buffer, n, 0); //sends "n" bytes of data from "buffer" to socket "ns"
    close(ns); //closes the socket connection
    return close(cs); //closes the socket connection
}
