#include<iostream>
using namespace std;

class Stack{
    public: 
        int size;
        int top;
        int * arr;
};

// Check wether Stack is empty or not.
int isEmpty(Stack * ptr){
    if(ptr->top < 0){
        return 1;
    }
    return 0;
} 


int isFull(Stack * ptr){
    if(ptr->top == ptr->size -1){
        return 1;
    }
    return 0;
}

//Add(push) new data to tha Stack.
void Push(Stack * ptr, int data){
    if(isFull(ptr)){
        cout<<"Stack Overflow! can't push "<<data<<endl;
    }else{
        ptr->top += 1;
        ptr->arr[ptr->top] = data;
    }
}

//Remove(pop) Top of the element from the Stack.
void Pop(Stack * ptr){
    if(isEmpty(ptr)){
        cout<<"Stack Underflow! can't pop "<<ptr->arr[ptr->top]<<endl;
    }else{
        ptr->top -= 1;
    }
}

// Return a value from the user given position.
int peek(Stack * ptr, int position){
    int index = ptr->top - position + 1;
    if(index < 0){
        cout<<"Invalid position!!"<<endl;
        return -1;
    }
    return ptr->arr[index];
}

//display all the value following LIFO order.
void Display(Stack * ptr){
    for (int i = 1; i <= ptr->top + 1; i++)
    {
        cout<<" "<<peek(ptr, i)<<endl;
    }

    cout<<"*Note: Stack follow LIFO order(Last in first out)."<<endl;
}


int StackTop(Stack * ptr){
    if(isEmpty(ptr)){
        cout<<"No Element in this Stack."<<endl;
        return -1;
    }
    return ptr->arr[ptr->top];
}

int StackBottom(Stack * ptr){
    if(isEmpty(ptr)){
        cout<<"No Element in this Stack."<<endl;
        return -1;
    }
    return ptr->arr[0];
}


int main(){
    
    Stack * s = new Stack;

    s->size = 20;
    s->top = -1;
    s->arr = new int[s->size];

    Push(s, 20);
    Push(s, 7);
    Push(s, 4);
    Push(s, 17);
    Push(s, 10);
    Push(s, 35);
    Push(s, 78);

    Display(s);

    cout<<StackBottom(s)<<endl;

    return 0;
}