#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Node
{
    public:
    int data;
    Node* left,*right;
        Node(int data)
        {
            this->data=data;
            left=right=nullptr;
        }
};
Node* createNode(Node* &root,int value);
void buildTree(Node* &root,vector<int> vt)
{
    for (int i:vt)
    {
        root=createNode(root,i);
    }    
}
Node* createNode(Node* &root,int value)
{
    if(root==NULL)
    {
        root=new Node(value);    
    }
    else if(root->data>value)
    {
       root->left=createNode(root->left,value);
    }
    else
    {
        root->right=createNode(root->right,value);
    }
    return root;
}
void Inorder(Node* root)
{
    if(root==NULL)
        return;

    Inorder(root->left);
    cout<<root->data<<" ";
    Inorder(root->right);
}
void LevelOrderTravel(Node* root)
{
    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        Node* front=q.front();
        q.pop();

        cout<<front->data<<" ";
        
        if(front->left)
        {
            q.push(front->left);
        }
        
        if(front->right)
        {
            q.push(front->right);
        }   
    }  
}
int Maxvalue(Node* root)
{
    while (root->right!=NULL)
    {
        root=root->right;
    }
    return root->data;
}
int Minvalue(Node* root)
{
    while (root->left!=nullptr)
    {
        root=root->left;
    }
    return root->data;
    
}
int main()
{
    vector<int> vt{1,3,2,5,7,8};
    Node* root=NULL;
    buildTree(root,vt);
    Inorder(root);
    cout<<"\nLevelOrderTravel"<<endl;
    LevelOrderTravel(root);
    cout<<"\n---------------------------"<<endl;
    cout<<Minvalue(root)<<endl;
    cout<<Maxvalue(root)<<endl;
    return 0;
}