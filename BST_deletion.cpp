
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * left;
    Node * right;
    Node(int inp){
        this->data = inp;
        this->left = nullptr;
        this->right = nullptr;
    }
};

void InOrder_traversal(Node *root){
    if(root != nullptr){
        InOrder_traversal(root->left);
        cout<<root->data<<" ";
        InOrder_traversal(root->right);
    }
}

// In-order predecessor is roots left sub-trees right most element.
Node * InOrderPredecessor(Node * root){
    root = root->left;
    while(root->right != nullptr){
        root = root->right;
    }
    return root;
}


Node * Delete_Node(Node *root, int value){
    Node * in_pre;
    if(root == nullptr){
        return nullptr;
    }

    // For leaf Nodes.
    if (root->left == nullptr && root->right == nullptr)
    {
        delete root;
        return nullptr;
    }

 vv    // Search For deleted node.
    if (value < root->data)
    {
        root->left = Delete_Node(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = Delete_Node(root->right, value);  
    }

    else{
        in_pre = InOrderPredecessor(root);
        root->data = in_pre->data;
        root->left = Delete_Node(root->left, in_pre->data);
    }
    
    return root;
    
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

    InOrder_traversal(root);
    cout<<endl;
    Node * d = Delete_Node(root, 13);
    InOrder_traversal(root);


    return 0;
}