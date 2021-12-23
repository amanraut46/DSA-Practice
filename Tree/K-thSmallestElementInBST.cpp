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
void inorderTraversal(Node *, vector<int> &);
int KthSmallestElement(Node *root, int K)
{
    // add code here.
    vector<int> vt;
    inorderTraversal(root, vt);
    int n = vt.size();
    if (K > n)
        return -1;
    return vt[K - 1];
}
void inorderTraversal(Node *root, vector<int> &vt)
{
    if (!root)
        return;

    inorderTraversal(root->left, vt);
    vt.push_back(root->data);
    inorderTraversal(root->right, vt);
}
int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(9);
    cout <<KthSmallestElement(root, 2);
    return 0;
}