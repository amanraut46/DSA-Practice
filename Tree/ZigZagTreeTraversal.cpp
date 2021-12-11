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
vector<int> traversal(Node* root){
   
    vector<int> vt;
    bool istrue=true;
    
    stack<Node*> currentlevel;
    stack<Node*> nextlevel;
    currentlevel.push(root);
    while (!currentlevel.empty())
    {
        /* code */
        Node* temp=currentlevel.top();
        currentlevel.pop();

        if(temp){
            vt.push_back(temp->data);
            if(istrue){
            if(temp->left)
                nextlevel.push(temp->left);
            if(temp->right)
                nextlevel.push(temp->right);
        }
        else{
            if(temp->right)
                nextlevel.push(temp->right);
            if(temp->left)
                nextlevel.push(temp->left);  
            }
        }
        if(currentlevel.empty())
        {
            istrue=!(istrue);
            swap(currentlevel,nextlevel);
        }
        
    }
    return vt;
}
int main()
{
    Node* root=new Node(7);
    root->left=new Node(9);
    root->right=new Node(7);

    root->left->left=new Node(8);
    root->left->right=new Node(8);
    root->right->left=new Node(6);
    root->left->left->left=new Node(10);
    root->left->left->right=new Node(9);

    for(auto it: traversal(root)) 
        cout<<it<<" ";
    return 0;
}