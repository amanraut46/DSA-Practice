  #include<iostream>
#include<vector>
#include<stack>
#include <algorithm>
#include<queue>
using namespace std;
class Node
{
     public:
           int data;
           Node* left;
           Node* right;
            Node(int data)
            {
               this->data=data;
               left=nullptr;
               right=nullptr;
             }
};
int minValue(Node* root) {
    // Code here
    
    while(root->left){
        root=root->left;
    }
    return root->data;
    
    
}
int main()
{
    Node* root=new Node(5);
    root->left=new Node(4);
    root->right=new Node(6);
    root->right->right=new Node(7);
    root->left->left=new Node(3);
    root->left->left->left=new Node(1);
    cout<<"Min value:"<<minValue(root);
    return 0;
}