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
bool findNode(Node*,int);
void solve(Node*,Node*,int);
int c;
int countPair(Node* root1,Node* root2,int key){
    
    c=0;
    solve(root1,root2,key);
    return c;
    
}
void solve(Node* root1,Node* root2,int key){
    if(!root1){
        return;
    } 
    solve(root1->left,root2,key);
    if(findNode(root2,key-root1->data))
        c++;
    
    solve(root1->right,root2,key);
}
bool findNode(Node* root,int k){
    if(root==nullptr) return false;

    if(root->data==k) return true;

    bool x,y;
    if(k<root->data)
        x=findNode(root->left,k);
    else if(k>root->data)
        y=findNode(root->right,k);
    else
        return x or y;
    
}
int main()
{
    Node* root1=new Node(5);
    root1->left=new Node(3);
    root1->right=new Node(7);
    root1->left->left=new Node(2);
    root1->left->right=new Node(4);
    root1->right->left=new Node(6);
    root1->right->right=new Node(8);

    Node* root2=new Node(10);
    root2->left=new Node(6);
    root2->right=new Node(15);
    root2->left->left=new Node(3);
    root2->left->right=new Node(8);
    root2->right->left=new Node(11);
    root2->right->right=new Node(18);

    cout<<countPair(root1,root2,16);
    return 0;
}