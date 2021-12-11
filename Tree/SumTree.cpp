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
int sum(Node* root){

    if(root==NULL)
        return 0;
    return sum(root->left)+root->data+sum(root->right);
}
bool isSumTree(Node *root)
{
    // Your code here
    int ls,rs;

    if(root==nullptr || !(root->left)&& !(root->right)){
        return true;
    }
    ls=sum(root->left);
    rs=sum(root->right);

    if((root->data==ls+rs) && isSumTree(root->left) && isSumTree(root->right))
        return true;

    
    return false;  
}
int main()
{
    Node *root = new Node(3);
    root->left = new Node(1);
    root->right = new Node(2);
    cout<<isSumTree(root);
    return 0;
}