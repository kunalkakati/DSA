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

char Stack_top(Stack * st){
    return st->arr[st->top];
}

int Operator(char a){
    if(a == '+' || a == '-' || a == '/' || a == '*'){
        return 1;
    }
    return 0;
}

int Precedence(char p){
    if(p == '*' || p == '/'){
        return 2;
    }
    if(p == '+' || p == '-'){
        return 1;
    }
    return 0;
}




char * Postfix(char * infix){
   int length = strlen(infix);
   Stack * st = Create_Stack(length);
    char * postfix = (char *) malloc(length * sizeof(char));
    int i = 0;
    int j = 0;
    while (i != length)
    {
        if(!Operator(infix[i])){
            postfix[j] = infix[i];
            i++;
            j++;
        }else{
            if(Precedence(infix[i]) > Precedence(Stack_top(st))){
                Push(st, infix[i]);
                i++;
            }
            else{
                postfix[j] = Pop(st);
                j++;
            }
        }
    }
    while (!isEmpty(st))
    {
        postfix[j] = Pop(st);
        j++;
    }
    
    return postfix;


}



int main(){
    char str[100];
    printf("Enter your infix expression: ");
    scanf("%[^\n]s",str);
    
    printf("%s", Postfix(str));
    
    
    return 0;
}