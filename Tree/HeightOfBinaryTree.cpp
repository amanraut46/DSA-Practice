#include<iostream>
#include<vector>
#include<stack>
#include <algorithm>
#include<queue>
using namespace std;
class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data){
            this->data=data;
            left=nullptr;
            right=nullptr;
        }
};
int height(Node* top){

    if(top==nullptr) return 0;
    int lh=height(top->left);
    int rh=height(top->right);
    return max(lh,rh)+1;
}
int main()
{
    //    10
    //  /  \
    // 20   30
   // / \ 
   //40  60

    Node* root=new Node(10);

    root->left=new Node(20);

    root->right=new Node(30);

    root->left->left=new Node(40);
    root->left->right=new Node(60);

    cout<<"Height of Binary Tree:"<<height(root)<<" ";
    return 0;
}