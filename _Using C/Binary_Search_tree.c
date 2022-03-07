#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

Node *create_node(int data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void Insert_Node(Node *root, int data){
    Node * prv=NULL;
    while (root != NULL)
    {
        prv = root;
        if (data == root->data)
        {
            return;
        }
        else if (data < root->data)
        {
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    Node * nw_n = create_node(data);

    if (data < prv->data)
    {
        prv->left = nw_n;
    }else{
        prv->right = nw_n;
    }    
}

// Traversals:
void PreOrder(Node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        PreOrder(root->left);
        PreOrder(root->right);
    }
}
void InOrder(Node *root)
{
    if(root != NULL)
    {
        InOrder(root->left);
        printf("%d ", root->data);
        InOrder(root->right);
    }
}
void PostOrder(Node *root)
{
    if(root != NULL)
    {
        PostOrder(root->left);
        PostOrder(root->right);
        printf("%d ", root->data);
    }
}

Node * inOrder_Predecessor(Node * root){
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

Node * Delete_node(Node * root, int val){
    Node * ipre;

    if (root == NULL)
    {
        return NULL;
    }
    // for leaf nodes.
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }

    // Search deleted element.
    if(val < root->data){
        root->left = Delete_node(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = Delete_node(root->right, val);
    }

    else{
        ipre = inOrder_Predecessor(root);
        root->data = ipre->data;
        root->left = Delete_node(root->left, ipre->data);
    }
    
    return root;
    
}


int main()
{
    Node *root = create_node(40);
    Insert_Node(root, 33);
    Insert_Node(root, 98);
    Insert_Node(root, 62);
    Insert_Node(root, 13);
    Insert_Node(root, 23);

    InOrder(root);
    Delete_node(root,23);
    printf("\n");
    InOrder(root);


    return 0;
}