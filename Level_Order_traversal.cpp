#include<iostream>
#include<queue>
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

int Level_Counter(Node *root){
    int count_l = 1;
    int count_r = 1;

    if (root == nullptr)
    {
        return 0;
    }
    
    if (root->left != nullptr)
    {
        count_l = 1 + Level_Counter(root->left);
    }

    if (root->right != nullptr)
    {
        count_r = 1 + Level_Counter(root->right);
    }

    return count_r > count_l ? count_r : count_l;
}

void Print_current_level(Node * root, int level){
    if(root == nullptr){
        return;
    }
    if (level == 1)
    {
        cout<<root->data<<" ";
    }
    if(level > 1){
        Print_current_level(root->left, level-1);
        Print_current_level(root->right, level-1);
    }
    
}

void Level_Traversal(Node * root){
    int Level_Count = Level_Counter(root);

    for (int i = 1; i <= Level_Count; i++)
    {
        Print_current_level(root,i);
    }
    
}

// Another Algorithm:  
void Level_Traversal_using_Queue(Node *root){
    queue<Node*> Q;
    Q.push(root);

    while (!Q.empty())  
    {   
        // Queue first node(front node).
       Node * current_node = Q.front();
       // print
       cout<<current_node->data<<" ";

       if (current_node->left != nullptr)
       {
           Q.push(current_node->left);
       }

       if (current_node->right != nullptr)
       {
           Q.push(current_node->right);
       }
       
       // remove front node from queue.
       Q.pop();
       
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

    Level_Traversal(root);
    cout<<endl;
    Level_Traversal_using_Queue(root);

    return 0;
}