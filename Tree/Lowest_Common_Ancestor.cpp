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
void InOrder_traversal(Node *root){
    if(root != nullptr){
        InOrder_traversal(root->left);
        cout<<root->data<<" ";
        InOrder_traversal(root->right);
    }
}
// Recursive:
Node * LCA(Node *root, int v1,int v2){
    if(root == nullptr) return nullptr;

    //if v1 and v2 greater then root->data.
    if(root->data < v1 && root->data < v2){
        return LCA(root->right,v1,v2);
    }
    // if v1 and v2 smaller then root->data.
    if(root->data > v1 && root->data > v2){
        return LCA(root->left,v1,v2);
    }
    return root;
}

//iterative:
Node * LCA_itr(Node * root, int v1,int v2){
    while (root != nullptr)
    {
        if(v1 > root->data && v2 > root->data){
            root = root->right;
        }
        else if(v1 < root->data && v2 < root->data){
            root = root->left;
        }
        else break;
    }
    return root;
    
}
int main(){
    
    Node *root = new Node(20);
    Insert_in_BST(root, 20);
    Insert_in_BST(root, 5);
    Insert_in_BST(root, 16);
    Insert_in_BST(root, 40);
    Insert_in_BST(root, 25);
    Insert_in_BST(root, 42);
     InOrder_traversal(root);
    
    
    Node * l = LCA(root,5,42);
    Node * lr = LCA_itr(root,5,42);
    cout<<"\nLCA is: "<<l->data<<endl;
    cout<<"LCA(iterative way) is: "<<lr->data<<endl;


    return 0;
}