#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;cin>>s;
    int len=s.length();
    int num;
    if(len==1) num=s[0]-'0'; 
    else num=(s[len-2]-'0')*10+s[len-1]-'0';
    if(num%4==0) cout<<4<<endl;
    else cout<<0<<endl;
    return 0;
}