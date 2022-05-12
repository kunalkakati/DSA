#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node * next;
    node(int data){
        this->data = data;
        next = nullptr;
    }
};

class Queue{
    node *front,*rear;
    public:
    Queue(){
        front = rear = nullptr;
    }

    void enqueue(int data){
        node * n = new node(data);

        if(rear == nullptr){
            front = rear = n;
            return;
        }

        rear->next = n;
        rear = n;
    }

    void dequeue(){
        if(front == nullptr){
            return;
        }

        node * de = front;
        front = front->next;

        if(front == nullptr){
            rear = nullptr;
        }
        delete de;
    }

    void print_Q(){
        node * p = front;

        while (p != nullptr)
        {
            cout<<p->data<<" ";
            p = p->next;
        }
        cout<<endl;
        
    }

    int Queue_front(){
        return front->data;
    }
};


int main(){
    Queue q;
    
    q.enqueue(22);
    q.enqueue(44);
    q.enqueue(55);
    q.enqueue(59);
    q.dequeue();
    q.Queue_front();
    q.print_Q();
    


    return 0;
}
