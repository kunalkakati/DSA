#include <iostream>
#include <string>
using namespace std;

class Stack
{
public:
    int size;
    int top;
    char *arr;
};

int isEmpty(Stack *ptr)  
{
    if (ptr->top < 0)
    {
        return 1;
    }
    return 0;
}

void Push(Stack *ptr, char data)
{
    ptr->top += 1;
    ptr->arr[ptr->top] = data;
}

char Pop(Stack *ptr)
{
    char prv;
    prv = ptr->arr[ptr->top];
    if (isEmpty(ptr))
    {
        cout << "Perenthesis Unmatched.----" << endl;
    }
    else
    {
        ptr->top -= 1;
    }
    return prv;
}

int match(char a, char b)
{
    if (a == '{' && b == '}' || a == '[' && b == ']' || a == '(' && b == ')')
    {
        return 1;
    }
    return 0;
}

int main()
{
    string str;
    cout << "Write..." << endl;
    cin >> str;
    cout << endl;
    cout << endl;
    Stack *st = new Stack;
    st->size = str.length();
    st->top = -1;
    st->arr = new char[st->size];
    char poped_elem;

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '{' || str[i] == '(' || str[i] == '[')
        {
            Push(st, str[i]);
        }
        if (str[i] == '}' || str[i] == ')' || str[i] == ']')
        {
            poped_elem = Pop(st);
            if(!match(poped_elem, str[i])){
                Push(st,poped_elem);
                break;
            }
        }


        
    }

    if (isEmpty(st))
    {
        cout << "Perenthesis matched." << endl;
    }
    else
    {
        cout << "Perenthesis Unmatched." << endl;
    }

    return 0;
}