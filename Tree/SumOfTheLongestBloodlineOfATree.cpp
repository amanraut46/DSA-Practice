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

int sumOfLongRootToLeafPathUtil(Node*);
void sumOfLongRootToLeafPath(Node* root,
int sum,int len,int& maxLen,int& maxsum){
    if(root==NULL){
        if(maxLen<len){
            maxLen=len;
            maxsum=sum;
        }
        else if(maxLen==len && maxsum<sum)
        {
            maxsum=sum;
        }
        return;
    }
    sumOfLongRootToLeafPath(root->left, sum + root->data,len + 1, maxLen, maxsum);
    sumOfLongRootToLeafPath(root->right, sum + root->data,len + 1, maxLen, maxsum);
}
int sumOfLongRootToLeafPathUtil(Node *root)
{
    //code here
    if(root==NULL)
        return 0;
    int maxSum=INT32_MIN;
    int maxLen=0;
    sumOfLongRootToLeafPath(root,0,0,maxLen,maxSum);
    return maxSum;
}
int main()
{
    //    4        
    //   / \       
    //  2   5      
    // / \ / \     
    //7  1 2  3    
    //  /
    // 6
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right->right = new Node(5);
    root->left->left = new Node(7);
    root->left->right = new Node(1);
    root->left->right->left = new Node(6);
    root->right->left = new Node(2);
    root->right->right = new Node(3);
    cout<<sumOfLongRootToLeafPathUtil(root);
    return 0;
}