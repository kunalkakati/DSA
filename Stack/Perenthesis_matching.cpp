#include<iostream>
#include<string>
using namespace std;

class Stack{
    public:
        int size;
        int top;
        char * arr;
};

int isEmpty(Stack * ptr){
    if (ptr->top < 0)
    {
        return 1;
    }
    return 0;
}

void Push(Stack * ptr){
        ptr->top += 1;
        ptr->arr[ptr->top] = '(';
}

void Pop(Stack * ptr){
    if(isEmpty(ptr)){
        cout<<"Perenthesis Unmatched."<<endl;
    }else{
        ptr->top -= 1;
    }
}


int main(){
    string str;
    cout<<"Write..."<<endl;
    cin>>str;
    Stack * st = new Stack;
    st->size = str.length();
    st->top = -1;
    st->arr = new char[st->size];
    
    for (int  i = 0; i < str.length(); i++)
    {
        if(str[i] == '('){
            Push(st);
        }
        if(str[i] == ')'){
            Pop(st);
        }
    }
    
    if(isEmpty(st)){
        cout<<"Perenthesis matched."<<endl;
    }else{
        cout<<"Perenthesis Unmatched."<<endl;
    }

    return 0;
}