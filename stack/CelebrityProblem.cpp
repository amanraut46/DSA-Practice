#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;


int main()
{
    vector<vector<int>> M{{0,1,0},
    {0,0,0},{0,1,0}};
    
    stack<int> st;

    for (int i = 0; i < M.size(); i++)
    {
        st.push(i);
    }
        
    while (st.size()>1)
    {
        int a=st.top();
        st.pop();
        int b=st.top();
        st.pop();

        if(M[a][b]==1){
            st.push(b);
        }
        else{
            st.push(a);
        }
    }
    int ans=st.top();

    int rowcount=0;
    int rowcheck=false;

    for (size_t i = 0; i < M.size(); i++)
    {
        if(M[ans][i]==0)
        rowcount++;
    }
    if(rowcount==M.size())
        rowcheck=true;
    
    int colcheck=false;
    int colcount=0;
    for (size_t i = 0; i < M.size(); i++)
    {
        if(M[i][ans]==1){
            colcount++;
        }
    }
    if(colcount==M.size()-1)
        colcheck=true;

    
    if(colcheck && rowcheck)
    {
        cout<<ans<<endl;
    }
    else{
         cout<<-1<<endl;
    }
    return 0;
}