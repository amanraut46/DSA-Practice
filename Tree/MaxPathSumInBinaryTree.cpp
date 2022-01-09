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
int maxPathSum(Node* tree){

    int mx=INT32_MAX;
    getMaxPath(&tree,mx);
    return mx;
}
int getMaxPath(Node* root,int &mx){

    if(!root) return 0;

    int l=getMaxPath(root->left,mx);
    int r=getMaxPath(root->right,mx);

    int single_max=max(max(l,r)+root->data+root->data);
    int top_max=max(single_max,l+r+root->data);

    mx=max(top_max,mx);

    return single_max;
    
}
int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);

    root->left->left=new Node(4);
    root->left->right=new Node(5);

    root->right->left=new Node(6);

    root->right->right=new Node(7);
    cout<<maxPathSum(root);
    return 0;
}