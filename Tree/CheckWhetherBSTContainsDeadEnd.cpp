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
bool solve(Node*,int,int);
bool isDeadEnd(Node *root)
{
    //Your code here
    return solve(root,1,INT32_MAX);
}
bool solve(Node* root,int minvalue,int maxvalue){
    if(!root) return false;
    if(minvalue==maxvalue) return true;
    bool l=solve(root->left,minvalue,root->data -1);
    bool r=solve(root->right,root->data+1,maxvalue);
    return  l || r;
}
int main()
{
    //           8
    //         /   \ 
    //       5      9
    //     /  \     
    //    2    7 
    //   /
    //  1     
    Node* root=new Node(8);
    root->left=new Node(5);
    root->right=new Node(9);
    root->left->left=new Node(2);
    root->left->right=new Node(7);

    root->left->left->left=new Node(1);
    cout<<isDeadEnd(root)<<endl;
    return 0;
}