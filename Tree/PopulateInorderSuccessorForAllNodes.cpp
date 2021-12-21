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
    Node* next;
    Node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
        next=nullptr;
    }
};
void populateNext(Node *root)
{
    // code here
    Node *prev = nullptr;
    solve(root, prev);
}
void solve(Node *root, Node *&prev)
{

    if (!root)
        return;

    solve(root->left, prev);

    if (prev != nullptr)
    {
        prev->next = root;
    }
    prev = root;

    solve(root->right, prev);
}
int main()
{
    return 0;
}