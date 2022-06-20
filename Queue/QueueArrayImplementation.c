#include<stdio.h>

int isEmpty(int,int);
int isFull(int,int,int);
int enqueue(int*,int*,int*,int,int);
int dequeue(int*,int*,int*,int);
void printQueue(int*,int,int);
int main(){
int rear =-1, front = -1;
int Queue[9];
int len  = 9;
enqueue(Queue,&front,&rear,2,len);
printQueue(Queue,rear,1);
enqueue(Queue,&front,&rear,5,len);
printQueue(Queue,rear,2);
enqueue(Queue,&front,&rear,8,len);
printQueue(Queue,rear,3);
enqueue(Queue,&front,&rear,12,len);
printQueue(Queue,rear,4);
dequeue(Queue,&rear,&front,9);
printQueue(Queue,rear,3);
dequeue(Queue,&rear,&front,9);
printQueue(Queue,rear,2);

    printf("\n");
    return 0;
}


int isEmpty(int rear, int front){
    if(rear == -1 && front == -1){
        return 1;
    }
    else{
        return 0; 
    }
}

int isFull(int rear,int front, int len){
   
    if((rear+1)%len == front){
        printf("\nQueue is Full");
        return 1;
    }
    else{
        return 0;
    }

}

int enqueue(int* Queue, int* front, int* rear, int x,int len){
    if(isFull(*rear,*front,len)){

        printf("\n enqueuedan dondu");
        return 0;
    }
    else if(isEmpty(*rear,*front)){
        *front = 0;
        *rear = 0;
     
    }
    else{
        *rear =(*rear+1)%len;    // we use the modulo so after we delete an element that index is reusable and not wasted!
    }
    Queue[*rear] = x;

    return 0;
}

int dequeue(int* Queue, int* rear, int*front,int len){
    if(isEmpty(*rear,*front)){
        return 0;
    }
    else if(*front == *rear){
        *front =-1;
        *rear = -1;
    }
    else{
        *front = (*front+1)%len;
    }
    return 0;

}

void printQueue(int* Queue, int rear,int len){
    int i;
    int print_index;
    printf("\n");
    for(i = 0; i<len; i++){
        print_index = (rear+i)%len;
        printf("%d ", Queue[print_index]);
    }
}