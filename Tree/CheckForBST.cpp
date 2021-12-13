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
    bool isBST(Node *root)
    {
        // Your code here
        vector<int> vt;
        getvalue(root, vt);

        for (int i = 1; i < vt.size(); i++)
        {
            if (vt[i] <= vt[i - 1])
                return false;
        }
        return true;
    }
    void getvalue(Node *root, vector<int> &vt)
    {

        if (root == nullptr)
            return;

        getvalue(root->left, vt);
        vt.push_back(root->data);
        getvalue(root->right, vt);
    }
};

int main()
{
    Node *root = new Node(2);
    root->left = new Node(1);
    root->right = new Node(3);
    cout<<root->isBST(root)<<endl;
    return 0;
}