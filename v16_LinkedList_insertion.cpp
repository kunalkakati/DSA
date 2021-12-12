#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void DisplyList(Node *head)
{
    while (head != NULL)
    {
        cout << "Element: " << head->data << endl;
        head = head->next;
    }
};

Node *insertFirst(Node *head, int data)
{
    Node *ptr = new Node;
    ptr->data = data;
    ptr->next = head;
    return ptr;
}

Node *insertEnd(Node *head, int data)
{
    Node *ptr = new Node;
    Node *p = head;
    ptr->data = data;

    while (p->next != NULL)
    {
        p = p->next;
    }

    ptr->next = NULL;
    p->next = ptr;

    return head;
};

Node * insertInBetween(Node *head, int index, int data){
    Node * ptr = new Node;
    Node * p = head;
    for(int i=0; i<=index-1; i++){
        p = p->next;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return head;
    
}

Node * insertAfterNode(Node *head, Node *prvElem, int data){
    Node *ptr = new Node;
    ptr->data = data;

    ptr->next = prvElem->next;
    prvElem->next = ptr;

    return head;
}

int main()
{

    Node *head = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *four = new Node;

    head->data = 12;
    head->next = second;

    second->data = 9;
    second->next = third;

    third->data = 2001;
    third->next = four;

    four->data = 30;
    four->next = NULL;

    DisplyList(head);
    head = insertAfterNode(head, third, 54);
    // head = insertInBetween(head, 3, 54);
    // head = insertEnd(head, 54);
    // head = insertFirst(head, 54);
    cout << endl;
    DisplyList(head);

    return 0;
}