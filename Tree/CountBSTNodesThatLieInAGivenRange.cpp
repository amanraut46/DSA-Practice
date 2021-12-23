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
void solve(Node*,int,int);
int c;
int getCount(Node *root, int l, int h)
{
  // your code goes here 
    c=0;
    solve(root,l,h);
    return c;
}
void solve(Node* root,int l,int h){
    if (!root) return;

    solve(root->left,l,h);
    if(l<= root->data && root->data <=h) c++;
    solve(root->right,l,h);
    
}
int main()
{
    Node* root=new Node(10);
    root->left=new Node(5);
    root->right=new Node(50);

    root->left->left=new Node(1);

    root->right->left=new Node(40);

    root->right->right=new Node(100);

    int l=5;
    int h=45;
    cout<<getCount(root,l,h)<<endl;
    return 0;
}