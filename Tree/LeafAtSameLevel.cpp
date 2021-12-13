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
    int ans;
    Node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
    bool check(Node *root)
    {
        //Your code here
        int ma = -1;
        int h = 0;
        ans = 1;
        solve(root, h, ma);
        return ans;
    }
    void solve(Node *root, int h, int &ma)
    {
        if (!root)
            return;

        if (ans == 0)
            return;

        if (!root->left && !root->right){
            if (ma == -1)
                ma = h;
            else
            {
                if (h != ma)
                    ans = 0;
            }
        }
        solve(root->left,h+1,ma);
        solve(root->right,h+1,ma);
    }
};
int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);

    root->left->left = new Node(10);
    root->left->right = new Node(15);
    return 0;
}