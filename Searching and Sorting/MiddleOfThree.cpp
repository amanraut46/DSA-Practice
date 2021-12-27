#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;
int middle(int A, int B, int C){
        //code here//Position this line where user code will be pasted.
        vector<int> vt;
        vt.push_back(A);
        vt.push_back(B);
        vt.push_back(C);
        
        sort(vt.begin(),vt.end());
        
        return vt[1];
        
    }
int main()
{
    cout<<middle(978,518,300);
    return 0;
}