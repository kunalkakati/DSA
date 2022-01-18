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

int Height(Node *root){
    int count_l = 0;
    int count_r = 0;

    if (root == nullptr)
    {
        return 0;
    }
    
    if (root->left != nullptr)
    {
        count_l = 1 + Height(root->left);
    }

    if (root->right != nullptr)
    {
        count_r = 1 + Height(root->right);
    }

    return count_r > count_l ? count_r : count_l;
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

    cout<<"Height: "<<Height(root)<<endl;

    return 0;
}