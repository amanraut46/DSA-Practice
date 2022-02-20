#include<iostream>
#include<queue>

using namespace std;
void solve(queue<int> &q,int c,int k){

    if(c>=k)
        return;
    
    int x=q.front();
    q.pop();
    solve(q,c+1,k);
    q.push(x);
}
int main(){

    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    int k=2;
    int c=0;
    solve(q,c,k);

    while (!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    
    return 0;
}