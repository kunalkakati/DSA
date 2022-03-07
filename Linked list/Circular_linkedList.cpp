#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void DisplayList(Node *head)
{
    Node *p = head;
    do
    {
        cout << "Element: " << p->data << endl;
        p = p->next;

    } while (p != head);
}

Node *InsertFirst(Node *head, int data)
{
    Node * newNode = new Node;
    newNode->data = data;
   
   Node *p = head->next;
   while (p->next != head)
   {
       p = p->next;
   }
   p->next = newNode;
   newNode->next = head;
   // now start from newNode in this circular Linked list.
   head = newNode;
   return head;
};

Node * InsertLast(Node *head, int data){
     Node * newNode = new Node;
    newNode->data = data;
   
   Node *p = head->next;
   while (p->next != head)
   {
       p = p->next;
   }
   p->next = newNode;
   newNode->next = head;
   return head;
}

Node * InsertInBetween(Node *head, int index, int data){
    Node * newNode = new Node;
    newNode->data = data;
    Node *p = head->next;
    while ( p->next != head)
    {
        p = p->next;
    }
    for (int i = 0; i <= index-1; i++)
    {
        p = p->next;
    }
    newNode->next = p->next;
    p->next = newNode;
    return head;
}

Node * InsertAfterNode(Node *head, Node * prvNode, int data){
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = prvNode->next;
    prvNode->next = newNode;
    return head;
}

void SearchNode(Node *head, int num){
    Node *p = head;
    int i =0;
    int res = 0;
    do{
        if (p->data == num)
        {
            res = 1;
            break;
        }
        i++;
        p = p->next;
    }while(p != head);

    if(res != 0){
        cout<< "Value exist in position: "<<i<<endl;;
    }
    else{
        cout<< "does not exist"<<endl;
    }
}

int main()
{

    Node *head = new Node;
    Node *second = new Node;
    Node *third = new Node;
    Node *four = new Node;

    // empty circuler Node
    // head->next = head

    head->data = 12;
    head->next = second;

    second->data = 9;
    second->next = third;

    third->data = 2001;
    third->next = four;

    four->data = 30;
    four->next = head;

    DisplayList(head);
    cout << endl;
     SearchNode(head, 9);
    // head = InsertAfterNode(head,third, 5555);
    // head = InsertInBetween(head,2, 200);
    // head = InsertLast(head, 200);
    // head = InsertFirst(head, 200);
    // DisplayList(head);

    return 0;
}