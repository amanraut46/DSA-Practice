#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;
class BinaryTree
{
public:
    int data;
    BinaryTree *left;
    BinaryTree *right;
    BinaryTree(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};
struct TreeInfo{
    int diameter;
    int height;
};
TreeInfo getTreeInfo(BinaryTree *tree);
int binaryTreeDiameter(BinaryTree *tree) {
  // Write your code here.
  return getTreeInfo(tree).diameter;
}
TreeInfo getTreeInfo(BinaryTree *tree){

    if(tree==nullptr)
        return TreeInfo{0,0};

    TreeInfo leftTreeInfo=getTreeInfo(tree->left);
    TreeInfo rightTreeInfo=getTreeInfo(tree->right);

    int longestPath=leftTreeInfo.height+rightTreeInfo.height;

    int maxDiameter=max(leftTreeInfo.diameter,rightTreeInfo.diameter);

    int currentDiameter=max(longestPath,maxDiameter);

    int currentheight=1+max(leftTreeInfo.height,rightTreeInfo.height);
    return TreeInfo{currentDiameter,currentheight};
}
int main()
{
    BinaryTree* root=new BinaryTree(1);
    root->left=new BinaryTree(3);
    root->right=new BinaryTree(2);
    root->left->left=new BinaryTree(7);
    root->left->left->left=new BinaryTree(8);
    root->left->left->left->left=new BinaryTree(9);


    root->left->right=new BinaryTree(4);
    root->left->right->right=new BinaryTree(5);
    root->left->right->right->right=new BinaryTree(6);
    cout<<binaryTreeDiameter(root)<<"\n";
    return 0;
}