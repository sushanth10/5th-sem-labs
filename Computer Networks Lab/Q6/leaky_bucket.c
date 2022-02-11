#include<stdio.h>
#include<stdlib.h>
#define MIN(x,y) (x>y)?y:x

int main(int argc, char const *argv[])
{
    int inp[100]={0}, ch=0, filled, bucket_size=0, outrate=0, dropped=0, numsec=0, i=0, x=0;
    
    printf("-----LEAKY BUCKET ALGORITHM-----");
    printf("\nEnter the bucket size : ");
    scanf("%d", &bucket_size);
    printf("\nEnter output rate : ");
    scanf("%d", &outrate);
    printf("\n----------\n");

    do{
        printf("Enter number of incoming packets at second %d : ", (i+1));
        scanf("%d", &inp[i]);
        i++;
        printf("Enter 1 to continue input packets, 0 to exit : ");
        scanf("%d", &ch);
    }while(ch);

    numsec=i;

    printf("\n----------\n");
    printf("Second  Received  Output  Filled  Dropped \n");
    for(i=0; filled||i<numsec; i++){
        printf("   %d      ", (i+1));
        printf("%d       ", inp[i]);
        printf("%d      ", MIN(filled+inp[i], outrate));
        if((x=filled+inp[i]-outrate)>0){
            if(x>bucket_size){
                dropped = x-bucket_size;
                filled = bucket_size;
            }
            else{
                dropped=0;
                filled = x;
            }
        }
        else{
            dropped=0;
            filled=0;
        }
        printf("%d      ", filled);
        printf("%d\n", dropped);
            
    }

    printf("\n----------\n");

    return 0;
}
