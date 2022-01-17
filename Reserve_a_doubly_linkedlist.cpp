#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * prv;
    Node * next;
    Node(int input_data){
        this->data = input_data;
        this->prv = nullptr;
        this->next = nullptr;
    }
};



void Display(Node *head){
  Node *p = head;
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p->next != nullptr);

    cout << p->data << endl;


    cout<<endl;
}

Node * Reserve_doubly_linked_list(Node * head){
    Node * current = head;
    Node * prv = nullptr;
    Node * temp = nullptr;

    if(current == nullptr){
        return head;
    }

    while (current != nullptr)
    {
        temp = current->next;
        current->next = current->prv;
        current->prv = temp;

        prv = current;

        current = current->prv;         
    }
    
    return prv;
}

int main(){
    
    Node * head = new Node(4);
    Node * n1 = new Node(3);
    Node * n2 = new Node(2);
    Node * n3 = new Node(1);
    
    head->next = n1;
    
    n1->prv = head;
    n1->next = n2;

    n2->prv = n1;
    n2->next = n3;

    n3->prv = n2;
    
    Display(head);

    head = Reserve_doubly_linked_list(head);

    Display(head);



    return 0;
}