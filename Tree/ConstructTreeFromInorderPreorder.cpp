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
Node* treeBuild(int [],int [],int ,int);
int search(int [],int,int,int);
Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int start=0;
        return treeBuild(pre,in,start,n);
    }
    Node* treeBuild(int pre[],int in[],int start,int end){
        
        if(start>end) return NULL;
        
        static int index=0;
        int curr=pre[index];
        index++;
        Node* root=new Node(curr);
        if(start==end) return root;
        int pos=search(in,start,end,curr);
        
        root->left=treeBuild(pre,in,start,pos-1);
        root->right=treeBuild(pre,in,pos+1,end);
        
        return root;
    }
    int search(int in[],int start,int end,int curr){
        
        for(int i=start;i<=end;i++)
            {
                if(in[i]==curr) return i;
            }
            
    }
    void InoderTravels(Node* node){
        if(node==NULL) return;
        InoderTravels(node->left);
        cout<<node->data<<" ";
        InoderTravels(node->right); 
    }
int main()
{
    int inorder[] = {3, 1, 4 ,0 ,5 ,2};
    int preorder[] = {0 ,1 ,3 ,4 ,2, 5};
    int n=sizeof(inorder)/sizeof(inorder[0]);
    Node* node=buildTree(preorder,inorder,n);
    InoderTravels(node);
    return 0;
}