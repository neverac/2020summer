#include <bits/stdc++.h>
using namespace std;

string s;

int main(){
    int n;scanf("%d",&n);
    cin>>s;
    int ans=0;
    for(int i=0;i<n;i++){
        if(s[i]=='+') ans++;
        if(s[i]=='-') if(ans>0) ans--;
    }
    cout<<ans<<endl;
    return 0;
}