#include <iostream>  
  
using namespace std;  
  
struct node {  
    int element;  
    struct node* left;  
    struct node* right;  
};  
  
/*Createing a new node*/  
struct node* createNode(int val)  
{  
    struct node* Node = (struct node*)malloc(sizeof(struct node));  
    Node->element = val;  
    Node->left = NULL;  
    Node->right = NULL;  
  
    return (Node);  
}  
  
/*to traverse the nodes of binary tree in preorder*/  
void traversePreorder(struct node* root)  
{  
    if (root == NULL)  
        return;  
    cout<<" "<<root->element<<" ";  
    traversePreorder(root->left);  
    traversePreorder(root->right);  
}  
  
/*to traverse the nodes of binary tree in Inorder*/  
void traverseInorder(struct node* root)  
{  
    if (root == NULL)  
        return;  
    traverseInorder(root->left);  
    cout<<" "<<root->element<<" ";  
    traverseInorder(root->right);  
}  
  
/*to traverse the nodes of binary tree in postorder*/  
void traversePostorder(struct node* root)  
{  
    if (root == NULL)  
        return;  
    traversePostorder(root->left);  
    traversePostorder(root->right);  
    cout<<" "<<root->element<<" ";  
}  
  
int main()  
{  
    struct node* root = createNode(38);  
    root->left = createNode(28);  
    root->right = createNode(48);  
    root->left->left = createNode(23);  
    root->left->right = createNode(33);  
    root->left->left->left = createNode(13);  
    root->left->left->right = createNode(26);  
    root->right->left = createNode(43);  
    root->right->right = createNode(58);  
    root->right->right->left = createNode(53);  
    root->right->right->right = createNode(68);  
    cout<<"\n The Preorder traversal of given binary tree is -\n";  
    traversePreorder(root);  
      
    cout<<"\n The Inorder traversal of given binary tree is -\n";  
    traverseInorder(root);  
      
    cout<<"\n The Postorder traversal of given binary tree is -\n";  
    traversePostorder(root);  
    return 0;  
}  
/*Abir kundu
11:30 pm
25 september 2023*/