#include<iostream>
using namespace std;

class Queue{
    public:
    int size;
    int front;
    int rear;
    int * arr;
};

int isEmpty(Queue * q){
    if(q->front == q->rear){
        return 1;
    }
    return 0;
}

int isFull(Queue * q){
    if(q->front == q->size -1){
        return 1;
    }
    return 0;
}

void enqueue(Queue * q, int data){
    if (isFull(q))
    {
        cout<<"Queue overflow"<<endl;
    }else{
        q->front += 1;
        q->arr[q->front] = data;
    }
}

void dequeue(Queue * q){
    if (isEmpty(q))
    {
        cout<<"Queue Underflow."<<endl;
    }else{
        q->rear += 1;
    }
    
}

int peek(Queue * q, int index){
    if (isEmpty(q))
    {
        cout<<"Queue Underflow."<<endl;
        return 0;
    }
    return q->arr[q->front + index];
}



int main(){
    Queue * q = new Queue;
    q->size = 20;
    q->front = -1;
    q->rear = -1;
    q->arr = new int[q->size];
    enqueue(q,22);
    enqueue(q,4);
    enqueue(q,56);
    enqueue(q,12);
    for (int i = q->rear + 1; i <= q->front; i++)
    {
        cout<<peek(q,i)<< " ";
    }
    
   
    


    return 0;
}