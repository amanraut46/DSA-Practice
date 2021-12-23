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
    };
    Node *flatten(Node *parent)
    {
        // Dummy node
        Node *dummy = new Node(-1);

        // Pointer to previous element
        Node *prev = dummy;

        // Calling in-order traversal
        inorder(parent, prev);

        prev->left = NULL;
        prev->right = NULL;
        Node *ret = dummy->right;

        // Delete dummy node
        delete dummy;
        return ret;
    };
    void inorder(Node* root,Node* &prev){
        if(!root) return;

        inorder(root->left,prev);
        prev->left=nullptr;
        prev->right=root;
        prev=root;
        inorder(root->right,prev);
    }
    void printNode(Node* root){
       
       if(!root) return;

        cout<<root->data<<" ";
        printNode(root->right);
    };
};
int main()
{
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(7);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(8);

    root->printNode(root->flatten(root));
    return 0;
}