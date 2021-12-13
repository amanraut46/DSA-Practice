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
Node *case1(Node *top, Node *prev, Node *target);
Node *case2(Node *top, Node *prev, Node *target);
Node *case3(Node *top, Node *prev, Node *target);
void Inorder(Node *root);
Node *deleteNode(Node *top, int key)
{

    Node *root = top;
    Node *prev = NULL;
    if (!root)
        return NULL;
    while (root)
    {
        if(key==root->data)
            break;
        prev = root;
        if (root->data > key)
            root = root->left;
        else if (root->data < key)
            root = root->right;
    }
    if (root == NULL)
        cout << "Not print" << endl;
    else if (root->left!=NULL && root->right!=NULL)
        root = case3(top, prev, root);
    else if (root->left && root->right==NULL)
        root = case2(top, prev, root);
    else if (root->left==NULL && root->right)
        root = case2(top, prev, root);
    else if (root->left==NULL && root->right==NULL)
        root = case1(top, prev, root);

    return top;
}
Node *case1(Node *top, Node *prev, Node *target)
{
    if (prev == nullptr)
        top = NULL;
    else if (target == prev->left)
        prev->left = NULL;
    else if (target == prev->right)
        prev->right = NULL;

    free(target);
    return top;
}
Node *case2(Node *top, Node *prev, Node *target)
{
    Node *child=NULL;
    if(target->left!=NULL)
        child=target->left;
    else
        child=target->right;
    
    if(prev->left==target)
        prev->left=child;
    else if(prev->right==target)
        prev->right=child;
    else
        top=child;
    free(target);

    return top;
}
Node *case3(Node *top, Node *prev, Node *target)
{
    Node *succ,*prevdic;
    return top;
}
void Inorder(Node *root)
{
    if (root == NULL)
        return;

    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}
int main()
{
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->right = new Node(7);
    int key = 4;
    Inorder(root);
    root = deleteNode(root, key);
    cout<<endl;
    Inorder(root);
    return 0;
}