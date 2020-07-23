#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int len = s.size();
    int ans = 0;
    int a = 0, b = 0;
    int cur = 0;
    for(int i = 0; i < len; i++){
        if(s[i] == '-') ++b;
        else ++a;
        if(b - a > cur) cur = b - a;
    }
    for(int i = 0; i < len; i++){
        if(s[i] == '-') cur--;
        else cur++;
    }
    cout<<cur<<endl;

    return 0;
}