#include<iostream>

using namespace std;

bool areRotations(string str1,string str2){

    if(str1.length()!=str2.length())
        return false;
    
    string temp=str1+str1;
    cout<<temp<<endl;
    return (temp.find(str2)!=string::npos);

}
int main(){
    string str1="AACD";
    string str2="ACDA";
    cout<<areRotations(str1,str2);
    return 0;

}