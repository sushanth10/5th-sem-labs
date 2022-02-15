#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int checksum(int fl){
    
    int n, i=0, sum, temp;
    char inp[100];

    scanf("%s", inp);
    // We get half of the length
    if(strlen(inp)%2==0)
        n=strlen(inp)/2;
    else
        n=(strlen(inp)+1)/2;

    // Each character makes 8-bits. So, combine it with next one character to form 16-bit fragment.
    // the sum of these 16-bit fragments will form the checksum. 
    for(i=0; i<n; i++){
        temp = inp[i*2];
        temp = temp*256 + inp[(i*2)+1];
        sum += temp;
    }

    if(fl==1){
        printf("Enter checksum value : ");
        scanf("%x", &temp);
        sum += temp;
    }

    // This is to fit the checksum if it is grater than 65536
    if(sum/65536 != 0){
        n = sum%65536;
        sum = (sum/65536)+n;
    }

    // get the complement of it
    sum = 65535-sum;
    printf("%x\n", sum);
    return sum;
}

int main(int argc, char const *argv[])
{
    printf("-----CHECKSUM-----\n");
    printf("\nOPTIONS\n");
    printf("1. Encode\n2. Decode\n3. Exit\n");
    printf("----------\n");

    int ch, sum=0;

    printf("Enter choice : ");
    scanf("%d", &ch);
    
    do{

        switch (ch){    
            case 1: printf("Enter String : ");
                    sum = checksum(0);
                    printf("Value of checksum is : %x\n", sum);
                break;
            case 2 :    printf("Enter the received string : ");
                    sum = checksum(1);
                    if(sum != 0)
                        printf("Data received is invalid.\n");
                    else
                        printf("Valid data received.\n");
                break;
            case 3 : exit(0);
                break;
            
            default: printf("Invalid choice.");
                break;
            }

            printf("----------\n");

            printf("Enter choice : ");
            scanf("%d", &ch);

    }while(ch>0);
    return 0;
}

