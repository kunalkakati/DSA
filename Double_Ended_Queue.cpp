#include<iostream>
using namespace std;

class DEqueue{
    public:
        int size;
        int f;
        int r;
        int * arr;
};

//? initialize DEqueue as a globel variable.
DEqueue * q = new DEqueue;




void Enqueue_front(int data){
    if (q->f == -1)
    {
        cout<<"Queue Overflow! from front."<<endl;
    }else{
        q->f -= 1;
        q->arr[q->f] = data;
    }
}

void Enqueue_rear(int data){
    if(q->r == q->size -1){
        cout<<"Queue Overflow! from rear."<<endl;
    }else{
        q->r += 1;
        q->arr[q->r] = data;
    }
}

void Dequeue_front(){
    if (q->f == q->r)
    {
        cout<<"Queue Underflow from front. can't dequeue."<<endl;
    }else{
        q->f += 1;
    }
}

void Dequeue_rear(){
    if (q->r == q->f)
    {
        cout<<"Queue Underflow from rear. Can't Dequeue."<<endl;
    }else{
        q->r -= 1;
    }
    
}

void PrintQueue(){
    for (int i = q->f; i < q->r + 1; i++)
    {
       cout<<q->arr[i]<<" ";
    }
}

//if you need to Enqueue from front the you have to Dequeue first.(3 Dequeue = 3 Enqueue).
int main(){
    q->size = 30;
    q->f = q->r = -1;
    q->arr = new int[q->size];
    Enqueue_rear(3);
    Enqueue_rear(3);
    Enqueue_rear(3);
    Enqueue_rear(3);
    Dequeue_front();
    Dequeue_front();
    Enqueue_front(44);
    Enqueue_front(45);
    Dequeue_rear();
    PrintQueue();
    
    return 0;
}
