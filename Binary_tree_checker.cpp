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

int isBST(Node *root){
    static Node *prv = nullptr;
    if (root != nullptr)
    {
        // first check left subtree, if left subtree is not Binary search tree return 0.
        if(!isBST(root->left)){
            return 0;
        }
        // then check privous element are smaller then present element. if not return 0.
        if (prv != nullptr && prv->data >= root->data)
        {
            return 0;
        }
        // set privous as present root.
        prv = root;
        // if all other condition are satisfied return right sub tree. (if right sub tree also a Binary search tree recurson call until it not get leaf(node who points to null) node then return 1). 
        return isBST(root->right);
        
    }else{
        return 1;
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
    
    cout<<isBST(root)<<endl;

    


    return 0;
}