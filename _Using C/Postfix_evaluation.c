#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Stack
{
    int top;
    int size;
    int * arr;
}Stack;

Stack * Create_Stack(int size){
    Stack * nw_s = (Stack *) malloc(sizeof(Stack));
    nw_s->top = -1;
    nw_s->size = size;
    nw_s->arr = (int *) malloc(nw_s->size*sizeof(int));
    return nw_s;
}

int isEmpty(Stack *st){
    if(st->top < 0){
        return 1;
    }
    return 0;
}

int isFull(Stack * st){
    if(st->top >= st->size-1){
        return 1;
    }
    return 0;
}

void Push(Stack *st, int data){
    if(!isFull(st)){
        st->top +=1;
        st->arr[st->top] = data;
        return;
    }
    printf("Stack Overflow!\n");
}

int pop(Stack *st){
    if(!isEmpty(st)){
        int d = st->arr[st->top];
        st->top -= 1;
        return d;
    }
    printf("Stack underflow!\n");
}

void PrintStack(Stack *st){
    for (int i = st->top; i >= 0; i--)
    {
        printf("%d\n", st->arr[i]);
    }
    
}

int doMaths(int v1,int v2,char op){
    int res;

    switch (op)
    {
    case '+':
        res = v1 + v2;
        break;
    case '-':
        res = v1 - v2;
        break;
    case '/':
        res = v1 / v2;
        break;
    case '*':
        res = v1 * v2;
        break;
    }

    return res;
}

int Postfix_evaluation(char * arr){
    int s = strlen(arr);
    Stack * st = Create_Stack(s);
    int p1,p2,math;
    
    for (int i = 0; i < s; i++)
    {
        if(arr[i] == '-' || arr[i] == '*' || arr[i] == '+' || arr[i] == '/'){
            p1 = pop(st);
            p2 = pop(st);
            math = doMaths(p1,p2,arr[i]);
            Push(st,math);
        }
        else{
            int it = arr[i]-'0';
            Push(st,it);
        }
    }
    
    int result = pop(st);

    if(!isEmpty(st)){
        printf("Wrong postfix expression.\n");
        return -99;
    }

    return result;
    
    
}


int main(){
    char postfix[100] = "43*5-";
    int r = Postfix_evaluation(postfix);

    printf("%d \n", r);
    return 0;
}