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
void CalculateBranchSum(Node* root,int item,vector<int> &vt);
vector<int> branchSums(Node *root) {
  // Write your code here.
	vector<int> arr;
	CalculateBranchSum(root,0,arr);
    return arr;
}
void CalculateBranchSum(Node* root,int item,vector<int> &vt){

    if(root==NULL) return;

    int newrunning=item+root->data;
    if(root->left==NULL && root->right==NULL){
        vt.push_back(newrunning);
    }
    CalculateBranchSum(root->left,newrunning,vt);
    CalculateBranchSum(root->right,newrunning,vt);
}
int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);
    root->left->left=new Node(4);
    root->left->right=new Node(5);

    root->left->left->left=new Node(8);

    root->left->left->right=new Node(9);

    root->right->left=new Node(6);

    root->right->right=new Node(7);
    
    vector<int> result=branchSums(root);
    for(auto it:result){
        cout<<it<<" ";
    }
    return 0;
}