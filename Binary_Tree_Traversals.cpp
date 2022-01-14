#include<iostream>
using namespace std;

class Node{
    public:
    Node * left;
    int data;
    Node * right;
};

Node * CreateNode(int data){
    Node * New_Node = new Node;
    New_Node->data = data;
    New_Node->left = nullptr;
    New_Node->right = nullptr;
    return New_Node;
}

// Traversal: Preorder, Postorder, Inorder.

//Preorder: root->left->right.
void PreOrder(Node * root){
    if(root != nullptr){
        cout<<root->data<<" "; //*diff
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

// Postorder: left->right->root.
void PostOrder(Node * root){
    if(root != nullptr){
        PostOrder(root->left);
        PostOrder(root->right);
        cout<<root->data<<" "; //*diff
    }
}

//Inorder: left->root->right.
void InOrder(Node * root){
    if(root != nullptr){
        InOrder(root->left);
        cout<<root->data<<" "; //*diff
        InOrder(root->right);
    }
}

int main(){

    Node * root = CreateNode(20);
    Node * n1 = CreateNode(5);
    Node * n2 = CreateNode(15);
    Node * n3 = CreateNode(2);

    root->left = n1;
    root->right = n2;

    n1->left = n3;

    PreOrder(root);
    cout<<endl;
    PostOrder(root);
    cout<<endl;
    InOrder(root);


    return 0;
}