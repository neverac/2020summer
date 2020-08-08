#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int maxn  =2e5+100;
ll a[maxn],lsum[maxn],rsum[maxn],lm,rm;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        memset(lsum,0,sizeof(lsum));
        memset(rsum,0,sizeof(rsum));
        ll maxx=-INF;
        for (int i=1;i<=n;i++) {
            cin >> a[i];
            lsum[i] = lsum[i-1]+a[i];
            if (lsum[i]>maxx) maxx=lsum[i],lm = i;
        }
        maxx=-INF;
        for (int i=n;i>=1;i--) {
            rsum[i] = rsum[i+1]+a[i];
            if (rsum[i]>maxx) maxx = rsum[i],rm=i;
        }
        if (lm==n && rm==1)  cout << "YES" << endl;
        else{
            if (lsum[lm]-lsum[rm-1]>=lsum[n]) cout <<"NO" << endl;
            else cout <<"YES" << endl;
        }
    }
}


//        ll sum=0;
//        memset(dp,0,sizeof(dp));
//        for (int i=1;i<=n;i++) {
//            cin >>a[i];
//            sum+=a[i];
//        }
////        int now = a[1];
//        dp[1] = a[1];
//        for (int i=2;i<=n;i++){
//            if (dp[i-1]) dp[i]=dp[i-1]+a[i]; else dp[i] = a[i];
//        }
//        long long ans = dp[1];
//        for (int i=2;i<=n;i++)
//            ans=max(ans,dp[i]);
//        if ()