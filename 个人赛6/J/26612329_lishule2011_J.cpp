#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    int ans = 0,x;
    for (int i=1;i<=n;i++){
        cin >> x;
        ans += (x/k);
        if (x%k>0) ans++;
    }
    if (ans%2 == 1) ans=ans/2+1;
    else ans/=2;
    cout << ans;
}