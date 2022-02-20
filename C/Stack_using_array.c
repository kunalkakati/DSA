#include<stdio.h>
#include<stdlib.h>

typedef struct Stack{
    int top;
    int size;
    int * arr;
}Stack;

Stack * Create_Stack(int size){
    Stack * st = (Stack *) malloc(sizeof(Stack));
    st->top = -1;
    st->size = size;
    st->arr = (int *) malloc(st->size * sizeof(int));
    return st;
}

int isEmpty(Stack * st){
    if(st->top < 0){
        return 1;
    }
    return 0;
}

int isFull(Stack * st){
    if(st->top >= st->size - 1){
        return 1;
    }
    return 0;
}

void Push(Stack * st, int data){
    if(isFull(st)){
        printf("Satck overflow!\n");
        return;
    }
    st->top += 1;
    st->arr[st->top] = data;
}

void Stack_traversal(Stack * st){
    for (int i = 0; i <= st->top; i++)
    {
        printf("%d ",st->arr[i]);
    }
    printf("\n");
}

void Pop(Stack * st){
    if(isEmpty(st)){
        printf("Stack underflow!\n");
        return;
    }
    st->top -= 1;
}

int Peek(Stack * st, int position){
    int index =  st->top - position + 1;
    if(index < 0){
        printf("Invalid position.\n");
        return -1;
    }
    return st->arr[index];
}


int main(){
    Stack * st = Create_Stack(20);
    Push(st,33);
    Push(st,44);
    Push(st,21);
    Stack_traversal(st);
    Pop(st);
    Stack_traversal(st);
    printf("%d \n", Peek(st,2));
    



    return 0;
}