#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    struct Node *prv;
    struct Node *next;
} Node;

void DisplayDaublyLinkedList(Node *head)
{
    Node *p = head;
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p->next != NULL);

    cout << p->data << endl;

    //    cout<<"...................................."<<endl;
    // Reverse print:
    //    do{
    //        cout<<"element: "<<p->data<<endl;
    //        p = p->prv;
    //    }while( p != NULL);
}

// Insertion:
Node *Insert_At_First_Node(Node *head, int data)
{
    Node *p = head;
    Node *n = new Node;
    n->data = data;
    if (p != NULL)
    {
        n->prv = NULL;
        n->next = p;
        p->prv = n;
    }
    else
    {
        p = n;
    }

    return n;
}

Node *Insert_At_Last_Node(Node *head, int data)
{
    Node *p = head;
    Node *nw_n = new Node;
    nw_n->data = data;
    if (nw_n != NULL)
    {
        do
        {
            p = p->next;
        } while (p->next != NULL);
        nw_n->next = NULL;
        nw_n->prv = p;
        p->next = nw_n;
    }

    return head;
}

Node *Insert_before_a_Index(Node *head, int data, int index)
{
    Node *p = head;
    Node *nw_n = new Node;
    nw_n->data = data;
    if (p == NULL)
    {
        p = nw_n;
        return nw_n;
    }
    else
    {
        for (int i = 0; i < index; i++)
        {
            p = p->next;
        }
        nw_n->next = p->next;
        nw_n->prv = p;
        p->next = nw_n;
    }

    return head;
}

// Deletion:

Node *Delete_first_Node(Node *head)
{
    Node *p = head;
    Node *deleted_elem = p;

    if (p == NULL)
    {
        cout << "Linked list Underflow!" << endl;
        return head;
    }

    p = p->next;
    p->prv = NULL;

    cout << deleted_elem->data << " deleted." << endl;
    delete deleted_elem;

    return p;
}

Node *Delete_Last_Node(Node *head)
{
    Node *p = head;
    Node *n = head->next;
    Node *deleted_element = NULL;
    if (p == NULL)
    {
        cout << "Linked list does not have any element." << endl;
        return head;
    }

    do
    {
        p = p->next;
        n = n->next;
    } while (n->next != NULL);

    deleted_element = n;
    p->next = NULL;

    cout << deleted_element->data << " deleted." << endl;
    delete deleted_element;

    return head;
}

// index start whith 0 
// counting start second element of linked list.
// for example: 
// linked list: 22 34  77  92 45
// index:          0   1   2

Node * Delete_before_a_Index(Node * head, int index){
    Node *p = head;
    Node *q = head->next;
    Node * deleted_node;
    for (int i = 0; i < index; i++)
    {
        p = p->next;
        q= q->next;
    }
    if(p == NULL || q == NULL){
        cout<<"Delete before index does not delete first or last Node in a linked list! use another method"<<endl;
    }
    
    deleted_node = q;

    p->next = q->next;
    q->next->prv = p;
    
    cout<<deleted_node->data<<" deleted."<<endl;
    delete q;

    return deleted_node;
}

int main()
{

    Node *head = NULL;

    // Insert Node in Daubly linked list.
    head = Insert_At_First_Node(head, 33);
    head = Insert_At_First_Node(head, 64);
    head = Insert_At_Last_Node(head, 4);
    head = Insert_At_First_Node(head, 10);
    head = Insert_before_a_Index(head, 2, 1);
    // head = Delete_first_Node(head);
    // head = Delete_Last_Node(head);
    DisplayDaublyLinkedList(head);
    Node * d = Delete_before_a_Index(head,1);

    DisplayDaublyLinkedList(head);

    return 0;
}