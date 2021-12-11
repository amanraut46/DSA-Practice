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
vector<int> vt;

void printLeftSid(Node *root)
{
    if (!root)
        return;
    if (root->left)
    {
        vt.push_back(root->data);
        printLeftSid(root->left);
    }
    else if (root->right)
    {
        vt.push_back(root->data);
        printLeftSid(root->right);
    }
}
void printLeft(Node *root)
{
    if (!root)
        return;

    printLeft(root->left);

    if (!(root->left) && !(root->right))
        vt.push_back(root->data);

    printLeft(root->right);
}
void rightprint(Node *root)
{
    if (!root)
        return;
    if (root->right)
    {
        rightprint(root->right);
        vt.push_back(root->data);
    }
    else if (root->left)
    {
        rightprint(root->left);
        vt.push_back(root->data);
    }
}
int main()
{
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    root->right->right = new Node(25);
    printLeftSid(root);
    printLeft(root->left);
    printLeft(root->right);
    rightprint(root->right);
    for (int i : vt)
    {
        cout << i << " ";
    }
    return 0;
}