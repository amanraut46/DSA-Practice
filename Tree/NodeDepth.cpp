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
int nodeDepths(Node* root,int depth=0){

    if(root==NULL) return 0;

    return depth+nodeDepths(root->left,depth+1)+nodeDepths(root->right,depth+1);
}
int main()
{
    Node* root=new Node(1);

    root->left=new Node(2);
    root->right=new Node(3);

    root->left->left=new Node(4);
    root->left->right=new Node(5);

    root->left->left->left=new Node(8);

    root->left->left->right=new Node(9);

    root->right->right=new Node(7);

    root->right->left=new Node(6);

    cout<<nodeDepths(root);
    return 0;
}