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
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout << "LCA(4, 5) = " << lca(root, 4, 5)->data << endl;
    cout << "nLCA(4, 6) = " << lca(root, 4, 6)->data << endl;
    cout << "nLCA(3, 4) = " << lca(root, 3, 4)->data << endl;
    cout << "nLCA(2, 4) = " << lca(root, 2, 4)->data << endl;

    return 0;
}
