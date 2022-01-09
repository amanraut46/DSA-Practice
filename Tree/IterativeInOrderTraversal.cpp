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
    BinaryTree(int value)
    {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }
};
void iterativeInOrderTraversal(BinaryTree *tree,void (*callback)(BinaryTree *tree)) {
  // Write your code here.
}
int main()
{
    BinaryTree* node=new BinaryTree(1);
    node->left=new BinaryTree(2);
    node->right=new BinaryTree( 3);
    node->left->left=new BinaryTree(4);
    node->left->left->right=new BinaryTree(9);

    node->right->left=new BinaryTree(6);
    node->right->right=new BinaryTree(7);
    return 0;
}