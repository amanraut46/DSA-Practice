#include<iostream>
#include<vector>
#include<stack>
#include <algorithm>
#include<queue>
#include<map>

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
vector<int> topView(Node* root){
    queue<pair<Node*,int>> q;
    map<int,int> mp;

    q.push({root,0});

    while (!q.empty())
    {
        /* code */

        Node* temp=q.front().first;
        int h=q.front().second;
        q.pop();
        mp[h]=temp->data;
            
        if(temp->left!=NULL)
            q.push({temp->left,h-1});
        if(temp->right!=NULL)
            q.push({temp->right,h+1});
    }
    vector<int> vt;
    for(auto it:mp){
        vt.push_back(it.second);
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
    for(auto it:topView(root)){
        cout<<it<<" ";
    }
    return 0;
}