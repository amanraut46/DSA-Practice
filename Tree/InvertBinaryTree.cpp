#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};
void InvertBinaryTree(Node* root){

    if(root==NULL) return;

    Node* temp=root->left;
    root->left=root->right;
    root->right=temp;
    InvertBinaryTree(root->left);
    InvertBinaryTree(root->right);
}
void InOrder(Node* root){

    if(!root) return;

    InOrder(root->left);
    cout<<root->data<<" ";
    InOrder(root->right);
}
int main()
{
    Node* root=new Node(1);

    root->left=new Node(2);

    root->right=new Node(3);

    root->left->left=new Node(4);

    root->left->right=new Node(5);

    root->right->left=new Node(6);
    root->right->right=new Node(7);

    root->left->left->left=new Node(8);
    root->left->left->right=new Node(9);
    InOrder(root);
    cout<<endl;
    InvertBinaryTree(root);
    InOrder(root);
    return 0;
}