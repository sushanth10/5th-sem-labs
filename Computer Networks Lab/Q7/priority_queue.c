#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100

int queue[MAXSIZE];
int front=-1, rear=-1;

void insertIntoQueue(int packet){
    if(rear==MAXSIZE-1){
        printf("Queue Overflow\n");
    }
    if(front==-1 && rear==-1){
        queue[++rear] = packet;
        front++;
    }
    else{
        int i=rear;
        while(i>=front && queue[i]>packet){
            queue[i+1] = queue[i];
            i--;
        }
        queue[i] = packet;
        rear++;
    }
}

void removePacket(){
    if(front>rear){
        front=-1;
        rear=-1;
    }
    if(front==-1 && rear==-1){
        printf("Queue Underflow\n");
    }
    queue[front++] = -99;
    printf("Removed packet.\n");
}

void displayQueue(){
    int i=front;
    printf("Displaying queue : ");
    while(i<=rear){
        printf("%d ", queue[i++]);
    }
}

int main(int argc, char const *argv[])
{
    printf("--------------PROGRAM STARTS--------------\n");
    printf("MENU\n1. INSERT PACKET\n2. REMOVE PACKET\n3. DISPLAY QUEUE\n4. EXIT PROGRAM\n-------------------------------------\n");
    int ch, packet;
    printf("Enter choice : ");
    scanf("%d", &ch);
    while(ch>0){
        switch(ch){
            case 1 : printf("Enter packet priority value : ");
                    scanf("%d", &packet);
                    insertIntoQueue(packet);
                    break;
            case 2 : removePacket();
                    break;
            case 3 : displayQueue();
                    break;
            case 4 : exit(0);
                    break;
            default: printf("Invalid option.\n"); 
        }
        printf("\n-------------------------");
        printf("\nEnter choice : ");
        scanf("%d", &ch);
    }
    return 0;
}
