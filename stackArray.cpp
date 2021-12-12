#include<iostream>
using namespace std;

class Stack{
    public:
        int size;
        int top;
        int * arr;
};

int isEmpty(Stack *ptr){
    if(ptr->top < 0){
        return 1;
    }
    return 0;
}

int isFull(Stack * ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    return 0;
}

void StackPush(Stack * ptr, int data){
    if(isFull(ptr)){
        printf("Stack Overflow! can't push %d\n", data);
    }
    else{
        ptr->top += 1;
        ptr->arr[ptr->top] = data;
    }
}

void StackPop(Stack * ptr){
    if(isEmpty(ptr)){
        printf("Stack is Underflow.\n");
    }else{
        int value = ptr->arr[ptr->top];
        ptr->top -= 1;
        printf("Element %d Poped.\n", value);
    }
}

// position start with 1
int Peek(Stack * ptr, int position){
    if(ptr->top - position + 1 < 0){
        cout<<"Invalid Position";
        return -1;
    }

    return ptr->arr[ptr->top - position + 1];
}

void Display(Stack * ptr){
    for (int i = 1; i <= ptr->top +1 ; i++)
    {
        cout<<"Position "<<i<<" value "<<Peek(ptr, i)<<endl;
    }
    cout<<"*Note: Stack maintain LIFO order(last in first out)."<<endl;
}

int StackTop(Stack * ptr){
    return ptr->arr[ptr->top];
}

int StackBottom(Stack * ptr){
    return ptr->arr[0];
}

int main(){

    Stack * s = new Stack;

    s->size = 30;
    s->top = -1;
    s->arr = new int[s->size];

    StackPush(s, 88);
    StackPush(s, 32);
    StackPush(s, 9);
    StackPush(s, 76);
    StackPush(s, 12);
    // StackPop(s);
    
    Display(s);
    cout<<"Stack Top: "<<StackTop(s)<<"\nStack Bottom: "<<StackBottom(s)<<endl;
 
    return 0;
}