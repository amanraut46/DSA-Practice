#include<iostream>
#include<vector>

using namespace std;

vector<int> getSmaller(vector<int> vt){

    vector<int> result={};

    for(int i=1;i<vt.size();i++){

        if(vt[0]>vt[i])
            result.push_back(vt[i]);
    }
    return result;
}
vector<int> getBigger(vector<int> vt){
    vector<int> result={};

    for(int i=1;i<vt.size();i++){
        if(vt[0]<=vt[i])
            result.push_back(vt[i]);
    }
    return result;
}

bool sameBsts(vector<int> arrayOne, vector<int> arrayTwo) {
  
    if(arrayOne.size()!=arrayTwo.size())
        return false;
    if(arrayOne.size()==0 && arrayTwo.size()==0)
        return true;
    if(arrayOne[0]!=arrayTwo[0]) return false;

    vector<int> leftOne=getSmaller(arrayOne);
    vector<int> lefttwo=getSmaller(arrayTwo);

    vector<int> rightone=getBigger(arrayOne);
    vector<int> righttw=getBigger(arrayTwo);

    return sameBsts(leftOne,lefttwo) && sameBsts(rightone,righttw);
}

int main(){

    vector<int> a={10,15,8,12,94,81,5,2,11};

    vector<int> b={10,8,5,15,2,12,11,94,81};

    cout<<sameBsts(a,b);
    return 0;
}