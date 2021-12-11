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
int helper(Node*);
void toSumTree(Node *node)
{
    // Your code here
    int z = helper(node);
}
int helper(Node *root)
{
    if (!root)
        return 0;

    if (!root->left && !root->right)
    {
        int x = root->data;
        root->data = 0;
        return x;
    }
    int prev = root->data;
    root->data = helper(root->left) + helper(root->right);

    return prev + root->data;
}
void preOrder(Node *node)
{
    if (node == nullptr)
        return;
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}
int main()
{

    Node *root = new Node(10);
    root->right = new Node(6);
    root->left = new Node(-2);
    root->left->left = new Node(8);
    root->left->right = new Node(-4);
    root->right->left = new Node(7);
    root->right->right = new Node(5);
    preOrder(root);
    cout << endl;
    toSumTree(root);
    cout << endl;
    preOrder(root);
    return 0;
}