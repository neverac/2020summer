#include<cstdio>
#include<iostream>
using namespace std;
int main(){
    string s;
    int ans = 0;
    cin >> s;
    for(int i=0;i<s.length();i++){
        ans = (ans*10+s[i]-'0')%4;
    }
    if(ans==0){
        cout<<4<<endl;
    }
    else {
        cout<<0<<endl;
    }
    return 0;
}