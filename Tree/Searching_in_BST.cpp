#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * left;
    Node *right;
    Node(int input_data){
        this->data = input_data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

//Recursive way:

Node * Search(Node *root, int key){
    
        if (root == nullptr)
        {
            return nullptr;
        }
        if (key == root->data)
        {
            return root;
        }
        else if (key < root->data)
        {
            return Search(root->left, key);
        }
        else{
            return Search(root->right, key);
        }
    
}

int main(){

    Node *root = new Node(10);
    Node *n1 = new Node(7);
    Node *n2 = new Node(13);
    Node *n3 = new Node(3);
    Node *n4 = new Node(8);
    Node *n5 = new Node(11);

    root->left = n1;
    root->right = n2;

    n1->left = n3;
    n1->right = n4;

    n2->left = n5;
    
    Node * c = Search(root,11);

    if(c == nullptr){
        cout<<"Input does not exits"<<endl;
    }else{
        cout<<"Found: "<<c->data<<endl;
    }


    return 0;
}