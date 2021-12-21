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
vector<int> rightView(Node *root)
{
    vector<int> vt;

    queue<Node *> q;

    q.push(root);
    while (!q.empty())
    {
        /* code */
        int n = q.size();
        for (int i = n; i >= 1; i--)
        {
            /* code */
            Node *temp = q.front();
            q.pop();
            if (i == n)
                vt.push_back(temp->data);

            if (temp->right != nullptr)
            {
                q.push(temp->right);
            }
            if (temp->left != nullptr)
            {
                q.push(temp->left);
            }
        }
    }
    return vt;
}
int main()
{
    //       10
    //      /  /
    //     20   30
    //     / \ 
   //   40  60
    //  /
    // 70

    Node *root = new Node(10);

    root->left = new Node(20);

    root->right = new Node(30);

    root->left->left = new Node(40);
    root->left->right = new Node(60);
    root->left->left->left = new Node(70);
    for (auto i : rightView(root))
    {
        cout << i << " ";
    }
    return 0;
}