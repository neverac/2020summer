#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5+100;
ll a[maxn<<1];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i=1;i<=2*n;i++)cin >> a[i];
    sort(a+1,a+1+2*n);
    ll x = (a[n] - a[1]);
    ll y = (a[2*n] - a[n+1]);
    ll ans = x*y;
    for (int i=2;i<=n;i++){
        if ((a[i+n-1]-a[i])*(a[2*n]-a[1])<ans)
            ans =(a[i+n-1]-a[i])*(a[2*n]-a[1]);
    }
    cout << ans;
}