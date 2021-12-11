#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <map>
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
//map<int ,vector<int>> traversal(Node* root,int d,map<int,vector<int>> mp){
//
//    static  map<int,vector<int>>  mvp;
//    if(!root)
//        return mvp;
//
//    mvp[d].push_back(root->data);
//    mvp=traversal(root->left,d+1,mvp);
//    mvp=traversal(root->right,d,mvp);
//    return mvp;
//}

vector<int> traversal(Node *node)
{
    vector<int> vt;
    queue<Node *> q;

    q.push(node);
    while (!q.empty())
    {
        int n = q.size();

        while (n--)
        {
            Node *temp = q.front();

            q.pop();

            while (temp)
            {
                vt.push_back(temp->data);
                if (temp->left)
                    q.push(temp->left);

                temp = temp->right;
            }
        }
    }
    return vt;
}
int main()
{
    Node *root = new Node(8);
    root->left = new Node(3);
    root->left->left = new Node(1);
    root->right = new Node(10);
    root->right->left = new Node(6);
    root->right->left->left = new Node(4);
    root->right->left->right = new Node(7);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);

    for (auto it : traversal(root))
    {
        cout << it << " ";
    }
    return 0;
}