#include<iostream>
#include<queue>

using namespace std;

class Queues{

};
int main()
{
    queue<int> q;

    q.push(11);
    q.push(15);
    q.push(13);

    while (!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
     
    return 0;
}