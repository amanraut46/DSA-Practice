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
vector<int> Reverse(Node* root)
{
    vector<int> vt;
    stack<int> st;
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        /* code */

        Node* temp=q.front();

        q.pop();

        st.push(temp->data);

        
        if(temp->right!=nullptr)
            q.push(temp->right);

        if(temp->left!=nullptr)
            q.push(temp->left);
    }
    while(!st.empty()){

        vt.push_back(st.top());
        st.pop();
    }
    return vt;
    
}

int main(){
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

    for(auto i:Reverse(root)){
        cout<<i<<" ";
    }
    

}