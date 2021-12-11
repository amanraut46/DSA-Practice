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
Node* constructtree(string str,int *start){

    if(*start >=str.size() || str.size()==0 )
        return NULL;
    
    int num=0;

    while (*start<str.size() && str[*start]!='(' && str[*start]!=')')
    {
        /* code */
        int temp=(int)(str[*start]-'0');
        num=num*10+temp;
        *start=*start+1;
    }
    Node * root=new Node(num);
    if(*start>=str.size())
        return root;
    if(*start<str.size() && str[*start]=='(')
    {
        *start=*start+1;
        root->left=constructtree(str,start);
    }
    if(*start<str.size() && str[*start]==')')
    {
        *start=*start+1;
    }

    if(*start<str.size() && str[*start]=='(')
    {
        *start=*start+1;
        root->right=constructtree(str,start);
    }
    if(*start<str.size() && str[*start]==')')
    {
        *start=*start+1;
    }
    return root;
    
}
void preOrder(Node* root){

    if(!root) return;
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);

}
int main()
{
    string str = "4(2(3)(1))(6(5))";
    int start=0;
    Node* root = constructtree(str, &start);;
    preOrder(root);
    return 0;
}