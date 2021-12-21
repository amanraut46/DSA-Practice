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
void postorderIterative(Node* root){
    if(!root) return;

    stack<Node*> st;
    st.push(root);
    stack<int> out;

    while (!st.empty())
    {
        /* code */
        Node* curr=st.top();

        st.pop();

        out.push(curr->data);

        if(curr->left)
            st.push(curr->left);
        
        if(curr->right)
            st.push(curr->right);
    }
    while (!out.empty())
    {
        /* code */
        cout<<out.top()<<" ";
        out.pop();
    }
    
    
}
int main()
{
    /* Construct the following tree
               1
             /   \
            /     \
           2       3
          /      /   \
         /      /     \
        4      5       6
              / \
             /   \
            7     8
    */
 
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->right = new Node(8);
 
    postorderIterative(root);
    return 0;
}