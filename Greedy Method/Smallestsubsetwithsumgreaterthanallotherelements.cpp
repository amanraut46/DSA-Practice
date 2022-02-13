#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int minElement(vector<int> arr,int n){

    int halfsum=0;

    for (size_t i = 0; i < n; i++)
    {
        halfsum+=arr[i];
    }
    halfsum/=2;

    reverse(arr.begin(),arr.end());
    int curr_sum=0;
    int res=0;
    for (size_t i = 0; i < n; i++)
    {
        curr_sum+=arr[i];
        res++;

        if(curr_sum>halfsum)
            return res;
    }

    return res;
    
}

int main(){
    
    vector<int> arr{3,1,7,1};
    int n=arr.size();
    cout<<minElement(arr,n)<<endl;
    return 0;
}