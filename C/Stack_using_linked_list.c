#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node * next;
}Node;

Node * Create_Node(int data){
    Node * new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

Node * Create_Stack(){
    Node * head = NULL;
    return head;
}

int isEmpty(Node * st){
    if(st == NULL){
        return 1;
    }
    return 0;
}

int isFull(){
    Node * n = Create_Node(22);
    if(n == NULL){
        return 1;
    }
    return 0;
}

Node * push(Node * st,int data){
    Node * nw_n = Create_Node(data);
    if(isFull()){
        printf("Stack overflow!\n");
        return st;
    }
    if(isEmpty(st)){
        return nw_n;
    }
    nw_n->next = st;
    return nw_n;
}

Node * Pop(Node * st){
    if(isEmpty(st)){
        printf("Stack underflow!\n");
        return st;
    }
    Node * p = st;
    st = st->next;
    printf("Poped %d\n", p->data);
    free(p);
    return st;
}

void Stack_traversal(Node * st){
    while (st != NULL)
    {
        printf("%d ", st->data);
        st = st->next;
    }
    printf("\n");
    
}

int Peek(Node *st, int position){
    int count = 1;
    while (count < position && st != NULL)
    {
        st = st->next;
        count++;
    }
    return st != NULL ? st->data : -1;
}


int main(){
    Node * st = Create_Stack();
    
    st = push(st,22);
    st = push(st,30);
    st = push(st,40);
    st = push(st,50);
    st = push(st,60);
    Stack_traversal(st);
    st = Pop(st);
    st = Pop(st);
    Stack_traversal(st);
    printf("%d \n", Peek(st,3));
    

    return 0;
}