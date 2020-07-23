#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=100005;
ll dp[maxn][4];
ll a[maxn][2];

int main(){
    ll n;scanf("%lld",&n);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i][0]);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i][1]);
    for(ll i=1;i<=n;i++){
        dp[i][1]=max(dp[i-1][0]+a[i][0],dp[i-1][1]);
        dp[i][0]=max(dp[i-1][1]+a[i][1],dp[i-1][0]);
    }
    cout<<max(dp[n][1],dp[n][0])<<endl;
    return 0;
}