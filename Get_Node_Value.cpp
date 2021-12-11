#include<iostream>
using namespace std;


class Node{
    public:
        int data;
        Node* next;
    
    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
    int lenght(Node* root){
    int h=0;
    while(root!=NULL){
        h++;
        root=root->next;
    }
    return h;
}
int getNode(Node* llist, int positionFromTail) {
    Node* top=llist;
    int h=lenght(top);
    
    int getcount=h-positionFromTail;
    int i=0;
    if(getcount==0)
        return llist->data;
    while(i<getcount && llist!=nullptr)  {
    i++;
    llist=llist->next;
    }
    return llist->data;
}
    
};
int main(){
    Node *head=new Node(1);
    head->next=new Node(2);
    head->next->next=new Node(3);

    cout<<head->getNode(head,1)<<endl;
}