#include<stdio.h>
#include<stdlib.h>

typedef struct Queue{
    int size;
    int front;
    int rear;
    int * arr;
}Queue;


// -1 0 1 2 ..
//   [][][][][][]....
// ^
// front/rear
Queue * Create_queue(int size){
    Queue * new_queue = (Queue *) malloc(sizeof(Queue));
    new_queue->size = size;
    new_queue->front = -1;
    new_queue->rear = -1;
    new_queue->arr = (int *) malloc(new_queue->size * sizeof(int));
    return new_queue;
} 

int isFull(Queue * q){
    if(q->front == q->size - 1){
        return 1;
    }
    return 0;
}

int isEmpty(Queue * q){
    if( q->front == q->rear){
        return 1;
    }
    return 0;
}
// Enqueue:
//  queue-      [][][][][]
//              ^       ^
//             front   rear
         
void Enqueue(Queue * q, int data){
    if(isFull(q)){
        printf("Queue overflow!\n");
        return;
    }
    q->rear += 1;
    q->arr[q->rear] = data;
}
// Dequeue:
//  queue-      [][][][][]
//                ^     ^
//             front   rear
void Dequeue(Queue * q){
    if(isEmpty(q)){
        printf("Can't dequeue, queue underflow!\n");
        return;
    }
    q->front += 1;
}

void Queue_Treversal(Queue * q){
    int i = q->front;
    while (i != q->rear)
    {
        i++;
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

int Peek(Queue *q, int index){
    if(isEmpty(q)){
        printf("queue underflow!\n");
        return -1;
    }
    return q->arr[q->front + index];
}


int main(){
    Queue * q = Create_queue(20);
    Enqueue(q,22);
    Enqueue(q,3);
    Enqueue(q,56);
    Enqueue(q,12);
    Queue_Treversal(q);
    Dequeue(q);
    Enqueue(q,90);
    Queue_Treversal(q);

    printf("%d ", Peek(q,4));
    


    return 0;
}