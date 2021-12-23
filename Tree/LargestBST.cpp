#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;

struct Bst
{
    bool isBst;
    int size;
    int min;
    int max;
};
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
Bst largestBstFun(Node *root);
int largestBst(Node *root)
{
    // Your code here
    Bst b = largestBstFun(root);
    return b.size;
}
Bst largestBstFun(Node *root)
{
    if (!root)
    {
        Bst b = {true, 0, INT32_MAX, INT32_MIN};
        return b;
    }
    Bst l = largestBstFun(root->left);
    Bst r = largestBstFun(root->right);

    if (l.isBst and r.isBst and l.max < root->data and r.min > root->data)
    {
        Bst b = {true, 1 + l.size + r.size, min(l.min, root->data), max(r.max, root->data)};
        return b;
    }
    Bst b = {false, max(l.size, r.size), -1, -1};
    return b;
}
int main()
{
    Node *root = new Node(6);
    root->left = new Node(6);
    root->right = new Node(3);

    

    root->left->right = new Node(2);
    root->left->right->right = new Node(8);


    root->right->right=new Node(3);

    root->right->left=new Node(9);

    root->right->left->left=new Node(8);

    root->right->left->right=new Node(2);

    cout<<largestBst(root);
    return 0;
}