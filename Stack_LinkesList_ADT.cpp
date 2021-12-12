#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node * next;
};
Node * top = nullptr;

// O(1)
int isEmpty(){
    return top == nullptr ? 1 : 0;
}

//O(1);
int isFull(){
    Node * p = new Node;
    return p == NULL ? 1 : 0;
}

//O(n);
void Display(){
    Node * p = top;
    while (p != nullptr)
    {
        cout<<"Elment: "<<p->data<<endl;
        p = p->next;
    }
    cout<<"*Note: Stack follow LIFO(last in first out) order."<<endl;
}

//O(1);
void Push(int data){
    if (isFull())
    {
        cout<<"Stack is Overflow! can't push "<<data<<endl;
    }else{
        Node * nw = new Node;
        nw->data = data;
        nw->next = top;
        top = nw;
    }
}

//O(n)
void PushArray(int *arr, int size){
    for (int i = 0; i < 10; i++)
    {
        Push(arr[i]);
    }
}

//O(1);
void Pop(){
    if(isFull()){
        cout<<"Stack Underflow! can't pop "<<top->data<<endl;
    }
    else{
        Node * p = top;
        top = top->next;
        delete p;
        cout<<"Element Poped"<<endl;
    }
}

//O(n);
int peek(int position){
    Node * p = top;
    for (int i = 0; i != position -1 && p != nullptr; i++)
    {
        p = p->next;
    }
    return p != nullptr ? p->data : -1;
}

//O(1)
int StackTop(){
    return top->data;
}

//O(n);
int StackBottom(){
    Node * p = top;
    while (p->next != nullptr)
    {
        p = p->next;
    }
    return p->data;
}

int main(){
    int arr[10]= {1,2,3,4,5,6,7,8,9,10};
    PushArray(arr, 10);
    Pop();
    Display();
    // cout<<peek(2)<<endl;
    cout<<StackBottom()<<endl;
    cout<<StackTop()<<endl;

    return 0;
}