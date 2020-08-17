#include <bits/stdc++.h>
using namespace std;
string s0="tapioka",s00="bubble";

int main(){
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    int flag=0;
    if(s1!=s0&&s1!=s00) flag=1,cout<<s1<<" ";
    if(s2!=s0&&s2!=s00) flag=1,cout<<s2<<" ";
    if(s3!=s0&&s3!=s00) flag=1,cout<<s3<<" ";
    if(!flag) cout<<"nothing"<<endl;
    return 0;
}