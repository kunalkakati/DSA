#include<iostream>
#include<vector>
using namespace std;

class Stack{
    public:
        int size;
        int top;
        char * arr;
};

int isEmpty(Stack * st){
    if(st->top < 0){
        return 1;
    }
    return 0;
}

void push(Stack * st, char data){
    st->top += 1;
    st->arr[st->top] = data;
}

char pop(Stack * st){
    char prv_elem = st->arr[st->top];
    if(isEmpty(st)){
        return 0;
    }
    st->top -= 1;
    return prv_elem;
}

char StackTop(Stack * st){
    return st->arr[st->top];
}

int Operator(char ch){
    if (ch == '*' || ch == '+' || ch == '-' || ch == '/')
    {
        return 1;
    }
    return 0;
}

int Precidence(char ch){
    if (ch == '*' || ch == '/')
    {
       return 2;
    }
    else if(ch == '-' || ch == '+'){
        return 1;
    }
    return 0;
}

// string Convert_array_to_string(char arr[]){
//     string str = "";
//     int size = sizeof(arr)/sizeof(char);
//     for (int i = 0; i < size; i++)
//     {
//         str = str + arr[i];
//     }
//     return str;
// }

string infix_to_postfix(string infix){
    Stack * st = new Stack;
    st->size = 70;
    st->top = -1;
    st->arr = new char[st->size];

    char postfix[infix.length()];
    int i = 0;
    int j = 0;
    while(i != infix.length()){
        if(!Operator(infix[i])){
            postfix[j] = infix[i];
            i++;
            j++;
        }else{
            if(Precidence(infix[i]) > Precidence(StackTop(st))){
                push(st,infix[i]);
                i++;
            }else{
                postfix[j] = pop(st);
                j++;
            }
            
        }
    }
    while(!isEmpty(st)){
        postfix[j] = pop(st);
        j++;
    }

    return postfix;
}



int main(){
   
   string infix = "a*b/k+1";
    cout<<infix_to_postfix(infix)<<endl;



    return 0;
}