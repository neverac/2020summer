#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e3+100;
int a[maxn],dp[maxn][maxn];
inline int find(int r,int val){
    int x = lower_bound(a+1,a+r+1,val)-a;
    if (a[x] != val) return -1;
    else return x;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    int ans = 0;
    for (int i=1;i<=n;i++) cin >> a[i];

    sort(a+1,a+1+n);

    for (int i=1;i<=n;i++)
        for (int j=i-1;j>=1;j--){
            if (2*a[j]-a[i]<a[1]) break;
            int x = find(j-1,2*a[j]-a[i]);
            if (x == -1) continue;
            dp[i][j] = dp[j][x] + 1>dp[i][j]?dp[j][x] + 1:dp[i][j];
            ans = dp[i][j] > ans ? dp[i][j] : ans;
        }
    cout << ans+2 << endl;

}
