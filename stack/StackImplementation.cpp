#include<iostream>

using namespace std;

class StackClass
{
    int *arr;
    int top;
    int size;
    public:
        StackClass(int size){
            this->size=size;
            arr=new int[size];
            top=-1;
        };
        void Push(int value){

            if(size-top >=0){
                top++;
                arr[top]=value;
            }
            else{
                cout<<"Stack Overflow"<<endl;
            }
            
        }
        void Pop(){

            if(top >=0){
                int x=arr[top--];
                
            }
            else{
                cout<<"stack Underflow"<<endl;
            }
        }
        int peek(){
            if(top<0){
                cout<<"Stack is empty"<<endl;
                return 0;
            }
            else{
                int x=arr[top];
                return x;
            }
        }
        bool isempty(){
            return (top < 0);
        }
};

int main()
{
    StackClass c1(5);
    c1.Push(10);
    c1.Push(20);
    c1.Push(30);
    c1.Push(40);
    c1.Push(50);
    

    while (!c1.isempty())
    {
        cout<<c1.peek()<<" ";
        c1.Pop();
    }
    return 0;
}