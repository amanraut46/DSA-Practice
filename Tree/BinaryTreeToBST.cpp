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
void InorderTravesla(Node *, vector<int> &);
void ConvertToBST(Node*,vector<int>,int &);
Node *binaryTreeToBST(Node *root)
{
    // Your code goes here
    vector<int> vt;
    InorderTravesla(root, vt);
    sort(vt.begin(),vt.end());
    int i=0;
    ConvertToBST(root,vt,i);
    return root;
}
void ConvertToBST(Node* root,vector<int> vt,int &i){
    if(!root) return;

    ConvertToBST(root->left,vt,i);
    root->data=vt[i];
    i++;
    ConvertToBST(root->right,vt,i);
}
void InorderTravesla(Node *root, vector<int> &vt)
{
    if (!root)
        return;

    InorderTravesla(root->left, vt);
    vt.push_back(root->data);
    InorderTravesla(root->right, vt);
}
void Inorder(Node* root){
    if(!root) return;

    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root=binaryTreeToBST(root);
    Inorder(root);
    return 0;
}