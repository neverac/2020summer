#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll a,b;cin>>a>>b;
    ll ans=0;
    if(a>b) ans+=a/b,a%=b;
    while(a){
        if(a==1){
            ans+=b;
            break;
        }
        ans+=b/a;
        b%=a;
        swap(a,b);
    }
    cout<<ans<<endl;
    return 0;
}