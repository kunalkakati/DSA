#include<iostream>
using namespace std;

typedef struct Node{
    int data;
    struct Node * prv;
    struct Node * next;
}Node;

void DisplayDaubltLinkedList(Node *head){
    Node *p = head;
   do{
       cout<<"element: "<<p->data<<endl;
       p = p->next;
    }while (p->next != NULL);
    cout<<"element: "<<p->data<<endl;

   cout<<"...................................."<<endl;
   do{
       cout<<"element: "<<p->data<<endl;
       p = p->prv;
   }while( p != NULL);
    
}

Node * InsertAtFirstNode(Node *head, int data){
    Node *p = head;
    Node *n = new Node;
    n->data = data;

    n->prv = NULL;
    n->next = p;
    p->prv = n;

    return n;

}



int main(){
    
    Node * head = new Node;
    Node * second = new Node;
    Node * third = new Node;
    Node * four = new Node;

    head->prv = NULL;
    head->data = 20;
    head->next = second;

    second->prv = head;
    second->data = 35;
    second->next = third;

    third->prv = second;
    third->data = 57;
    third->next = four;

    four->prv = third;
    four->data = 98;
    four->next = NULL;

    DisplayDaubltLinkedList(head);
    cout<<endl;   
    cout<<endl;
    //Insert Node in Daubly linked list.
    head = InsertAtFirstNode(head, 33);
    DisplayDaubltLinkedList(head);


    return 0;
}