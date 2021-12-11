#include<iostream>
#include<vector>
#include<stack>
#include <algorithm>
#include<queue>
using namespace std;
class Node
{
     public:
           int data;
           Node* left;
           Node* right;
            Node(int data)
            {
               this->data=data;
               left=nullptr;
               right=nullptr;
             }
};
int height(Node* root){
    if(!root) return 0;
    return max(height(root->left),height(root->right))+1;
}
bool isbalnace(Node* root){
    if(!root)
        return true;
    
    int diff=abs(height(root->left)-height(root->right));
    if(diff<=1 && isbalnace(root->left) && isbalnace(root->right))
        return true;
    return false;
}
int main()
{
    Node *root=new Node(1);
    root->left=new Node(10);
    root->right=new Node(39);
    root->left->left=new Node(5);
    root->left->left->left=new Node(6);
    cout<<isbalnace(root);
    return 0;
}