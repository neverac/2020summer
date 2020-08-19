#include <bits/stdc++.h>
using namespace std;
const int N = 500;
int dp[N];
int a[N];
int n;
int main() {
    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i], a[i] += a[i-1];
    int ans = 360;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            ans = min(ans, abs((a[j] - a[i-1]) - (360 - (a[j] - a[i-1]))));
        }
    }
    cout << ans << endl;
            
}
            