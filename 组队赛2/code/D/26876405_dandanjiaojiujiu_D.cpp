#include<bits/stdc++.h>
using namespace std;
string s[4];
string ans[4];
int main(){
    int n = 0;
    cin>>s[1]>>s[2]>>s[3];
    for(int i = 1; i <= 3; i++){
        if(s[i] == "bubble" || s[i] == "tapioka") continue;
        else ans[++n] = s[i];
    }
    if(n == 0) cout<<"nothing"<<endl;
    else {
        for(int i = 1; i <= n; i++){
            cout<<ans[i];
            if(i != n) cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}