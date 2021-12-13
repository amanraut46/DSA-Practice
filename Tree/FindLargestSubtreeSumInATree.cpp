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
int LargeSum(Node* root,int &ans);
int findLargestSubtreeSum(Node* root){

    if(root==NULL) return 0;
    int ans=INT32_MIN;
    LargeSum(root,ans);
    return ans;
}
int LargeSum(Node* root,int &ans){
    
    if(root==NULL) return 0;

    int newsum=root->data+LargeSum(root->left,ans)+LargeSum(root->right,ans);
    ans=max(ans,newsum);

    return newsum;
}
int main()
{
    /*
               1
             /   \
            /     \
          -2       3
          / \     /  \
         /   \   /    \
        4     5 -6     2
    */
 
    Node* root = new Node(1);
    root->left = new Node(-2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(-6);
    root->right->right = new Node(2);
 
    cout << findLargestSubtreeSum(root);
    return 0;
}