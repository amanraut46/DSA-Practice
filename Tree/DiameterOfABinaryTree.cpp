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
int diameterOpt(Node* root,int *height){
        
        int lh=0;
        int rh=0;
        
        int ld=0;
        int rd=0;
        
        if(root==nullptr){
            *height=0;
            return 0;
        }
        ld=diameterOpt(root->left,&lh);
        rd=diameterOpt(root->right,&rh);
        
        *height=max(lh,rh)+1;
        
        return max(lh+rh+1,max(ld,rd));
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
    int h=0;
    cout<<diameterOpt(root,&h);
    return 0;
}