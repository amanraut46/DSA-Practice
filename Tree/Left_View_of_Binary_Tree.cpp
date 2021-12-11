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
vector<int> leftView(Node* root){
    vector<int> vt;

    queue<Node*> q;

    q.push(root);
    while (!q.empty())
    {
        /* code */
        int n=q.size();
        for (int i = 1; i <= n; i++)
        {
            /* code */
            Node* temp=q.front();
            q.pop();
            if(i==1)
                vt.push_back(temp->data);
            
            if(temp->left!=nullptr){
                q.push(temp->left);
            }
            if(temp->right!=nullptr){
                q.push(temp->right);
            }
        }
        
    }
    return vt;
    
}
int main()
{
    //       10
    //      /  /
    //     20   30
   //     / \ 
   //   40  60
   //  /
    //70   

    Node* root=new Node(10);

    root->left=new Node(20);

    root->right=new Node(30);

    root->left->left=new Node(40);
    root->left->right=new Node(60);
    root->left->left->left=new Node(70);
    for(auto i:leftView(root)){
        cout<<i<<" ";
    }
    return 0;
}