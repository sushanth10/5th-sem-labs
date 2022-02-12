Using TCP/IP sockets, write a client-server program to make client send the file name and the server to send back the contents of the requested file name "sample.txt" with the following contents : "Hello we are at computer networks lab". Display suitable error message in case the file is not present in the server.

# Steps to run the code

1. Compile the server side code and run the server first
            gcc server.c
            ./a.out

2. Open another terminal.

3. Compile and run client side code in it.
            gcc client.c
            ./a.out 127.0.0.1

4. When prompted for filename, enter "sample.txt"