#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node * next;
        Node(int input_data){
            this->data = input_data;
            this->next = nullptr;
        }
};

Node * head = nullptr;

void Insert(int data){
    Node * p = head;
    Node * nw_n = new Node(data);
    if (p == nullptr)
    {
        head = nw_n;
    }
    else{
        while (p->next != nullptr)
        {
            p =p->next;
        }
        p->next = nw_n;
    }
    
}

void Display(){
    Node * h = head;
    while (h != nullptr)
    {
        cout<<h->data<<" ";
        h = h->next;
    }
    cout<<endl;
}

void Delete_duplicates(){
    if (head == nullptr)
    {
        return;
    }
    Node * p = head;
    Node * a = nullptr;
    Node * b = nullptr;

    while (p != nullptr)
    {
        a = p;
        b = p->next;
        while (b != nullptr)
        {
            if (a->data == b->data)
            {
                a->next = b->next;
            }else{
                a = b;
            }
            b = b->next;
        }
        p = p->next;
    }
    
    
}

int main(){
    
    Insert(1);
    Insert(2);
    Insert(3);
    Insert(3);
    Insert(3);
    Insert(3);
    Insert(3);
    Insert(4);
    Display();
    Delete_duplicates();
    Display();

    return 0;
}