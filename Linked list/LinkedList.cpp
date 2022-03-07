#include<iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

void DisplayList(Node*);


int main(){
    Node * head = new Node;
    Node * second = new Node;
    Node * third = new Node;

    head->data = 7;
    head->next = second;

    second->data = 44;
    second->next = third;

    third->data = 99;
    third->next = NULL;

    DisplayList(head);

    return 0;
}

void DisplayList(Node* ptr){
    while (ptr != NULL)
    {
        cout<<"Element: "<<ptr->data<<endl;
        ptr = ptr->next;
    }
    
}