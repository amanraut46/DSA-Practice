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
void Preorder(Node*);
Node *post_order(int [], int);
Node *insert(Node *root, int x)
{ // I BREAK THE problem into 2 small problems
    Node *temp = new Node(x);
    if (root == NULL)
        return temp;
    if (root->left == NULL && root->data > x)
        root->left = temp;
    else if (root->right == NULL && root->data < x)
        root->right = temp;
    else if (root->data < x)
        return insert(root->right, x);
    else if (root->data > x)
        return insert(root->left, x);
}
Node *post_order(int pre[], int size)
{
    // code here
    Node *root = new Node(pre[0]);
    for (int i = 1; i < size; i++)
        insert(root, pre[i]);
    return root;
}
void Preorder(Node* root){

    if(!root) return;

    Preorder(root->left);
    Preorder(root->right);
    cout<<root->data<<" ";
}
int main()
{
    int N = 5;
    int arr[] = {40,30,35,80,100};
    Preorder(post_order(arr,N));
    return 0;
}