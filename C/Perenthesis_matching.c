#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Stack{
    int top;
    int size;
    char * arr;
}Stack;

Stack * Create_Stack(int size){
    Stack * st = (Stack *) malloc(sizeof(Stack));
    st->top = -1;
    st->size = size;
    st->arr = (char *) malloc(st->size * sizeof(char));
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


void Pop(Stack * st){
    if(isEmpty(st)){
        printf("Stack underflow!\n");
        return;
    }
    st->top -= 1;
}




int main(){
    char str[20];
    printf("Enter your string: \n");
    scanf("%[^\n]s",str);
    int length = strlen(str);
    Stack * st = Create_Stack(length);

    for (int i = 0; i < length; i++)
    {
        if(str[i] == '{'){
            Push(st,'{');
        }
        if(str[i] == '}'){
            Pop(st);
        }
    }
    
    if(isEmpty(st)){
        printf("perenthesis matched.\n");
    }else
    {
        printf("Unmatched perenthesis.\n");
    }
    
    
    return 0;
}