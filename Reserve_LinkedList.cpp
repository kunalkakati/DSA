#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node * next;
};

void DisplayList(Node * head){
    while(head != nullptr){
        cout<<"Elem: "<<head->data<<endl;
        head = head->next;
    }
}

Node * ReserveList(Node * head){
    Node * prv = nullptr;
    Node * nex = nullptr;
    Node * curnt = head;

    while(curnt != nullptr){
        nex = curnt->next;
        curnt->next = prv;
        prv = curnt;
        curnt = nex;
    }
    return prv;
}


int main(){
    Node * head = new Node();
    Node * second = new Node();
    Node * Third = new Node();

    head->data = 7;
    head->next = second;

    second->data = 6;
    second->next = Third;

    Third->data = 8;
    Third->next = nullptr;
    
    DisplayList(head);
    head = ReserveList(head);
    cout<< "Reserve List:"<<endl;
    DisplayList(head);
    
    return 0;
}