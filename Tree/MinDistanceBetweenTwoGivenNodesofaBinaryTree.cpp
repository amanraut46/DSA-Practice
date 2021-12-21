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
int findDist(Node*,int,int);
Node *lca(Node*,int,int);
int FindDepth(Node*, int, int);
Node *lca(Node *root, int n1, int n2)
{
    // Your code here

    if (!root)
        return NULL;

    if (root->data == n1 || root->data == n2)
        return root;

    Node *left = lca(root->left, n1, n2);
    Node *right = lca(root->right, n1, n2);

    if (left && right)
        return root;

    else if (left == NULL)
        return right;
    else
        return left;
}
int FindDepth(Node *root, int h, int a)
{

    if (root == NULL)
        return -1;

    if (root->data == a)
        return h;
    int d1 = FindDepth(root->left, h + 1, a);
    int d2 = FindDepth(root->right, h + 1, a);

    if (d1 == -1)
        return d2;
    return d1;
}
int findDist(Node *root, int a, int b)
{
    // Your code here
    Node* temp=lca(root,a,b);
    int h=0;
    int d1=FindDepth(temp,h,a);
    int d2=FindDepth(temp,h,b);

    return d1+d2;
}
int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    cout<<findDist(root,3,4);
    return 0;
}