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

void Insert_in_BST(Node *root, int data){
    Node *prv = nullptr;
    
    while(root != nullptr){
        // store present root element.
        prv = root;

        if(data == root->data){
            cout<<data<<" alrady exist in the tree."<<endl;
            return;
        }
        //if data is smaller then root move root pointer to left.
        else if (data < root->data)
        {
            root = root->left;
        }
        // if not then move to the right.
        else{
            root = root->right;
        }
    }
    Node * nw_n = new Node(data);
    //if data is smaller then privous node data, link new_node to left pointer in privous node if not then right.
    if (prv->data > data)
    {
        prv->left = nw_n;
    }else{
        prv->right = nw_n;
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
    
    Insert_in_BST(root, 19);
    Insert_in_BST(root, 11);
    InOrder_traversal(root);


    return 0;
}