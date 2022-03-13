#include<iostream>

using namespace std;

class Node
{
    public:
        int data;
         Node* next;
        Node(int data)
        {
            this->data=data;
            this->next=NULL;
        }
};
void findLength(Node* head,int* l);
Node* findMiddle(Node* head)
{
    if(head==NULL)
        return NULL;
    Node* ptr1=head;
    Node* ptr2=head;

    int l=1;
    findLength(ptr1,&l);
    int i=1;
    while (i<=abs(l/2))
    {
        ptr2=ptr2->next;
        i++;
    }
    return ptr2;
}
void findLength(Node* head,int* l)
{
   if(head==NULL)
    return;

    findLength(head->next,l++);
    
}
int main()
{
    //1 2 3 4 5 -1
    Node* head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);
    head->next->next->next=new Node(4);
    head->next->next->next->next=new Node(5);
    head->next->next->next->next->next=new Node(-1);
    
    cout<<findMiddle(head)->data<<" ";
    return 0;
}