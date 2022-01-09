#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;
class BinaryTree
{
public:
    int value;
    BinaryTree *left;
    BinaryTree *right;
    BinaryTree(int data)
    {
        this->value = data;
        left = nullptr;
        right = nullptr;
    }
};
void addINBag(BinaryTree* tree,int d,int k,vector<int> &result);
int findDistance(BinaryTree* tree,int target,int k,vector<int> &result);
vector<int> findNodesDistanceK(BinaryTree *tree, int target, int k) {
  // Write your code here.
  vector<int> result;
  findDistance(tree,target,k,result);
  return result;
}
int findDistance(BinaryTree* tree,int target,int k,vector<int> &result){

    if(tree==nullptr) return -1;

    if(tree->value==target){
        addINBag(tree,0,k,result);
        return 1;
    }
    int ld=findDistance(tree->left,target,k,result);
    int rd=findDistance(tree->right,target,k,result);
    
    if(ld==k || rd==k)
        result.push_back(tree->value);
    if(ld!=-1){
        addINBag(tree->right,ld+1,k,result);
        return ld+1;
    }
    if(rd!=-1){
        addINBag(tree->left,rd+1,k,result);
        return rd+1;
    }
    return -1; 
}
void addINBag(BinaryTree* tree,int d,int k,vector<int> &result){
    if(tree==NULL) return;

    if(d==k)
        result.push_back(tree->value);
    else{
      addINBag(tree->left,d+1,k,result);
    addINBag(tree->right,d+1,k,result);
    }
}

int main()
{
    BinaryTree* root=new BinaryTree(1);
    root->left=new BinaryTree(2);
    root->right=new BinaryTree(3);

    root->left->left=new BinaryTree(4);
    root->left->right=new BinaryTree(5);
    root->right->right=new BinaryTree(6);

    root->right->right->left=new BinaryTree(7);
    root->right->right->right=new BinaryTree(8);
    int target=3;
    int k=2;
    vector<int> result=findBinaryTreesDistanceK(root,target,k);
    for(auto it:result){
        cout<<it<<" ";
    }
    return 0;
}