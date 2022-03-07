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
    if(q->front == 0 && q->rear == q->size -1 || q->rear == (q->front -1) % (q->size - 1)){
        return 1;
    }
    return 0;
} 

void Enqueue(Queue * q, int data){
    if(isFull(q)){
        cout<<"Queue Overflow!"<<endl;
    }
    else{
        q->rear = (q->rear + 1) % q->size;
        q->arr[q->rear] = data;
    }
}

int Dequeue(Queue * q){
    int dequeue_element = q->arr[q->front + 1];
    if (isEmpty(q))
    {
        cout<<"Queue Underflow!"<<endl;
        return 0;
    }
    else{
        q->front = (q->front + 1) % q->size;
    }
    return dequeue_element;
}
int main(){

    Queue *q = new Queue;
    q->size = 4;
    q->front = q->rear = -1;
    q->arr = new int[q->size];
    Enqueue(q,33);
    Enqueue(q,44);
    Enqueue(q,42);
    Enqueue(q,56);
    Enqueue(q,2);
    Enqueue(q,2);
    cout<<Dequeue(q)<<endl;
    // cout<<Dequeue(q)<<endl;
    if(isFull(q)){
        cout<<"Full"<<endl;
    }
    

    


    return 0;
}