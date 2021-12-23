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
Node* buildTreeUtil(vector<Node*> &,int,int);
void InordertGet(Node*,vector<Node*> &);
void Preorder(Node* root);
Node* buildTree(Node* root){

    vector<Node*> vt;
    InordertGet(root,vt);
    int start=0;
    int n=vt.size();
    return buildTreeUtil(vt,start,n-1);
}
Node* buildTreeUtil(vector<Node*> &vt,int start,int end){
    
    if(start>end) return NULL;
    int mid=(start+end)/2;

    Node *root=vt[mid];

    root->left=buildTreeUtil(vt,start,mid-1);
    root->right=buildTreeUtil(vt,mid+1,end);

    return root;
}
void InordertGet(Node* root,vector<Node*> &vt){

    if(!root) return;

    InordertGet(root->left,vt);
    vt.push_back(root);
    InordertGet(root->right,vt);
}
void Preorder(Node* root){
    if(!root) return;

    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
    
}
int main()
{
    /* Constructed skewed binary tree is
                10
               /
              8
             /
            7
           /
          6
         /
        5   */
 
    Node* root = new Node(10);
    root->left = new Node(8);
    root->left->left = new Node(7);
    root->left->left->left = new Node(6);
    root->left->left->left->left = new Node(5);
    Preorder(buildTree(root));
    return 0;
}