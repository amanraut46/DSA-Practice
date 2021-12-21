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
void printElement(vector<int>,int);
void printKPath(Node*, int);
void printPathUtil(Node*, vector<int> &, int);
void printKPath(Node *root, int k)
{

    vector<int> vt;

    printPathUtil(root, vt, k);
}
void printPathUtil(Node *root, vector<int> &vt, int k)
{
    if (root == nullptr)
        return;

    vt.push_back(root->data);

    printPathUtil(root->left, vt, k);
    printPathUtil(root->right, vt, k);

    int f = 0;
    for (int i = vt.size() - 1; i >= 0; i--)
    {
        f+=vt[i];
        if(f==k){
            printElement(vt,i);
        }
    }
    vt.pop_back();
}
void printElement(vector<int> vt,int j){
    for(int i=j;i<vt.size();i++)
    {
        cout<<vt[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    //    Input : k = 5
    //        Root of below binary tree:
    //           1
    //        /     \
    //      3        -1
    //    /   \     /   \
    //   2     1   4     5
    //        /   / \     \                    
    //       1   1   2     6

    Node *root = new Node(1);
    root->left = new Node(3);
    root->left->left = new Node(2);
    root->left->right = new Node(1);
    root->left->right->left = new Node(1);
    root->right = new Node(-1);
    root->right->left = new Node(4);
    root->right->left->left = new Node(1);
    root->right->left->right = new Node(2);
    root->right->right = new Node(5);
    root->right->right->right = new Node(2);

    int k = 5;
    printKPath(root, k);
    return 0;
}