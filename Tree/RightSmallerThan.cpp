#include<iostream>
#include<vector>

using namespace std;

vector<int> rightSmallerThan(vector<int> array) {
  
  vector<int> vt;

  for(int i=0;i<array.size();i++){

      int count=0;
      for(int j=i+1;j<array.size();j++){
          if(array[i]>array[j])
                count++;
      }
      vt.push_back(count);
  }
  return vt;
}
int main(){

    vector<int> vt={8,5,11,-1,3,4,2};

    vector<int> result=rightSmallerThan(vt);
    for(auto i:result){
        cout<<i<<" ";
    }

    return 0;
}