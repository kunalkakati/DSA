#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node * next;
};

int isEmpty(Node * ptr){
    if(ptr == nullptr){
        return 1;
    }
    return 0;
}

int isFull(){
    Node * p = new Node;
    if (p == nullptr)
    {
        return 1;
    }
    return 0;
}

Node * push(Node * top, int data){
    if (isFull())
    {
        cout<<"Stack Overflow."<<endl;
    }else{
        Node * elem = new Node;
        elem->data = data;
        elem->next = top;
        top = elem;
    }
    return top;
}

void Pop(Node ** top){
    if(isEmpty(*top)){
        cout<<"Stack is Underflow."<<endl;
    }
    else{
        Node * n = *top;
        *top = (*top)->next;
        delete n;
    }
        // return top;
}

void Display(Node * top){
    while (top != nullptr)
    {
        cout<<top->data<<endl;
        top = top->next;
    }
}


//
int Peek(Node * top, int position){
    Node * p = top;
    int i = 1;
    while (i < position && p != nullptr)
    {
        p = p->next;
        i++;
    }

   return p != nullptr ? p->data : -1;
    
}
//
int StackTop(Node * top){
    return isEmpty(top) ? -1 : top->data;
}
//
int StackBottom(Node * top){
    Node * p = top;
    while (p->next != nullptr)
    {
        p = p->next;
    }
    return p->data;
}


int main(){
    Node * top = nullptr;

    top = push(top, 43);
    top = push(top, 22);
    top = push(top, 6);
    top = push(top, 68); 
    top = push(top, 78); 
    top = push(top, 12); 
    Pop(&top);

    // Display(top);
    cout<<endl;

    cout<<Peek(top, 4)<<endl;
    cout<<"Stack Bottom: "<<StackBottom(top)<<endl;
    cout<<"Stack Top: "<<StackTop(top)<<endl;

    return 0;
}