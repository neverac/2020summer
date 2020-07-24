#include <bits/stdc++.h>
using namespace std;


int main(){
    string s;
    cin>>s;
    int a=0;
    for(int i=0;i<s.length();++i){
        a=(a*10+s[i]-'0')%4;
    }
    if(a==0) cout<<4;
    else cout<<0;
    return 0;

}
