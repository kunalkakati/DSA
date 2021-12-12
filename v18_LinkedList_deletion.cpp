#include<iostream>
using namespace std;

typedef struct Node{
    string data;
    struct Node * next;
}Node;


void DisplayList(Node *head){
    Node *p = head;
    int i =0;
    while (p->next != NULL)
    {
        cout<<i<<": "<<p->data<<endl;
        p = p->next;
        i++;
    }
    cout<<i<<": "<<p->data<<endl;
    
}

//Remove First Node

Node * RemoveFirstNode(Node *head){
    Node *p = head;
    head = head->next;
    delete p;
    return head;
}

//Remove in between Node

Node * RemoveInBetweenNode(Node *head, int index){
    Node *q = head;
    Node *p = head->next;

    for (int i = 0; i != index-1; i++)
    {
        q = q->next;
        p = p->next;
    }
    q->next = p->next;
    delete p;
    return head;
    
}

// Remove last Node in a linked list

Node * RemoveLastNode(Node *head){
    Node *p = head;
    Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    delete q;
    return head;
}

//Remove Node using that Nodes Value

Node * RemoveAfterANode(Node *head, string value){
    Node *p = head;
    Node *q = head->next;

    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    if (q->data == value)
    {
        p->next = q->next;
        delete q;
    }else{
        cout<<"Value not available in this Linked list";
    }
    return head;
    
}


int main(){
    Node *head = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *four = new Node;

    head->data = "Jeni";
    head->next = second;

    second->data = "Lisa";
    second->next = third;

    third->data = "jisso";
    third->next = four;

    four->data = "Rosee";
    four->next = NULL;

    DisplayList(head);
    // head = RemoveAfterANode(head,"Lisa");
    // head = RemoveLastNode(head);
    // head = RemoveInBetweenNode(head,2);
    // head = RemoveFirstNode(head);
    // cout<<endl;
    // DisplayList(head);
    


    return 0;
}