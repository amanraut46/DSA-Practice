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
void Insertnode(Node **top, int key)
{

    Node *root = *top;
    Node *new_node = new Node(key);
    while (root)
    {
        if (key < root->data)
            root = root->left;
        else if (key > root->data)
        {
            root = root->right;
        }
        else
        {
            cout << "Duplicate key";
        }
    }

    if (key < root->data)
    {
        root->left = new_node;
    }
    else if (key > root->data)
    {
        root->right = new_node;
    }
    else
    {
        root = new_node;
    }
}
Node *insert_node(Node *root, int key)
{
    Node *newnode = new Node(key);

    if (!root)
    {
        root = newnode;
    }

    if (key < root->data)
    {
        root->left = insert_node(root->left, key);
    }
    else if (key > root->data)
    {
        root->right = insert_node(root->right, key);
    }
    return root;

    //if(!root)
    //    root=newnode;
    //else if(key<root->data){
    //    root->left=newnode;
    //}
    //else{
    //    root->right=newnode;
    //}
}
void inorder(Node *root)
{
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
int main()
{
    Node *root = new Node(2);
    root->right = new Node(3);
    root->left = new Node(1);
    inorder(root);
    cout << endl;
    Insertnode(&root, 4);
    inorder(root);
    return 0;
}