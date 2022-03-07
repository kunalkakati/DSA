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


char Pop(Stack * st){
    if(isEmpty(st)){
        printf("Stack underflow!\n");
        return 'a';
    }
    char poped_elem = st->arr[st->top];
    st->top -= 1;
    return poped_elem;
}

int Match(char a, char b){
    if(a == '{' && b == '}' || a == '[' && b == ']' || a == '(' && b == ')' || a == '<' && b == '>' || a == '"' && b == '"'){
        return 1;
    }
    return 0;
}





int main(){
    char str[20];
    printf("Enter your string: \n");
    scanf("%[^\n]s",str);
    int length = strlen(str);
    Stack * st = Create_Stack(length);

    for (int i = 0; i < length; i++)
    {
        if(str[i] == '{' || str[i] == '(' || str[i] == '[' || str[i] == '<'){
            Push(st,str[i]);
        }
        if(str[i] == '}' || str[i] == ')' || str[i] == ']' || str[i] == '>'){

            char poped_element = Pop(st);
            if(!Match(poped_element,str[i])){
                Push(st,str[i]);
                break;
            }
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