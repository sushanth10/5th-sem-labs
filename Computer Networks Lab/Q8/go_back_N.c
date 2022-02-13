#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    printf("\n-----GOBACK-N ALGORITHM-----\n");

    // we need to know the number of packets to be sent, window size and the current packet (as first packet to send)
    int num_packets, wind_size, curr_packet=1;
    int expected = 1; // this is to keep track of acknowledgment number which shows the next expected packet 

    printf("Enter total number of packets : ");
    scanf("%d", &num_packets);
    printf("Enter window size : ");
    scanf("%d", &wind_size);

    do{
        int count=0;
        printf("\n-----------\n");
        printf("Sending packets : \n");

        while(count<wind_size && (curr_packet+count)<=num_packets){ //send packets until the window-size is completed or last packet is sent
            printf("Sent packet %d\n", curr_packet+count);
            count++;
        }
        printf("\n----------\n");

        printf("Enter ACK_NUM : ");
        scanf("%d", &expected); 

        // if ACK_NUM is less than the last packet sent or the next expected packet, then it is valid.
        // else it is invalid 
        if(expected>(curr_packet+count+1)){
            printf("Invalid ACK_NUM. Enter ACK_NUM again : ");
            scanf("%d", &expected);
        }

        // next expected packet is equal to ACK_NUM, which is the first packet to be sent 
        curr_packet=expected;
        
    }while(expected<num_packets+1); // repeat until ACK_NUM is 1 more than the last packet

    printf("\n\nAll packets sent have been received successfully\n");
    printf("\n-----END OF PROGRAM-----\n");
    return 0;
}
