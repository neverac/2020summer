#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll num[200005],sum[200005];

int main(){
    ll t;scanf("%lld",&t);
    while(t--){
        ll n;scanf("%lld",&n);
        for(ll i=1;i<=n;i++) scanf("%lld",&num[i]),sum[i]=sum[i-1]+num[i];
        ll ans=0,minn=sum[0];
        ll flag=0;
        ll r=0;
        for(ll i=1;i<=n;i++){
            if(sum[i]-minn>ans){
                ans=max(ans,sum[i]-minn);
                r=i;
            }
            if(sum[i]<=minn){
                minn=min(minn,sum[i]);
                flag=1;
            }
        }
        //cout<<r<<endl;
        if(ans<sum[n]) puts("YES");
        else if(flag==0&&ans==sum[n]&&r==n) puts("YES");
        else puts("NO");
    }
    return 0;
}