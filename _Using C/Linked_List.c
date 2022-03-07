#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;

Node * CreateNode(int data){
    Node * nw_n = (Node *) malloc(sizeof(Node));
    nw_n->data = data;
    nw_n->next = NULL;
    return nw_n;
}

void LinkedList_Traversal(Node *head){
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

Node * Insert_Node_at_last(Node *head,int data){
    Node * nw_n = CreateNode(data);
    Node * p = head;
    if(head == NULL){
        return nw_n;
    }

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = nw_n;
    return head;
}

Node * Insert_Node_at_first(Node *head, int data){
    Node * nw_n = CreateNode(data);
    if (head == NULL)
    {
        return nw_n;
    }

    nw_n->next = head;
    
    return nw_n;
    
}

//index start from 1.
Node * Insert_Node_at_index(Node *head, int data, int index){
    Node * nw_n = CreateNode(data);
    Node * p = head;
    if (head == NULL)
    {
        printf("Linked List empty. element inserted in index 1\n");
        return nw_n;
    }
    int counter = 1;
    while (counter < index-1)
    {
        p = p->next;
        counter++;
    }
    nw_n->next = p->next;
    p->next = nw_n;
    return head;
    
}

Node * Delete_first_node(Node * head){
    if(head == NULL){
        printf("List empty.\n");
        return head;
    }
    Node * delete_elem = head;
    head = head->next;
    printf("%d deleted.\n",delete_elem->data);
    free(delete_elem);
    return head;

}

Node * Delete_last_node(Node * head){
    if(head == NULL){
        printf("List empty.\n");
        return head;
    }
    Node * q = head;
    Node * p = head->next;
    while (p->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    q->next = NULL;
    printf("%d deleted.\n", p->data);
    free(p);
    return head;
    
}

// index start from 1.
// elem -   2 3 4 5 6
// index -    1 2 3
// first or last element connot be deleted using this function.
Node * Delete_node_at_index(Node *head, int index){
    if(head == NULL){
        printf("List empty.\n");
        return head;
    }
    Node * q = head;
    Node * p = head->next;
    int count = 1;
    while (count < index -1)
    {
        p = p->next;
        q = q->next;
        count ++;
    }
    q->next = p->next;
    printf("%d deleted.\n", p->data);
    free(p);
    return head;
}

Node * Search(Node *head,int key){
    while (head != NULL)
    {
        if(key == head->data){
            printf("%d found.\n",head->data);
            return head;
        }
        head = head->next;
    }

    printf("Element does not found.\n");
    return NULL;
    
}


int main(){

    Node * head = NULL;
    head = Insert_Node_at_last(head,33);
    head = Insert_Node_at_last(head,49);
    head = Insert_Node_at_last(head,23);
    head = Insert_Node_at_last(head,18);
    head = Insert_Node_at_first(head,22);
    head = Insert_Node_at_index(head,90,2);
    LinkedList_Traversal(head);

    head = Delete_first_node(head);
    head = Delete_last_node(head);
    head = Delete_node_at_index(head,1);

    LinkedList_Traversal(head);
    Node * e = Search(head,49);
    

    return 0;
}