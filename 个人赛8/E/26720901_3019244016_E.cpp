#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5 + 100;
long long a[N],f[N], g[N], n;
long long sum = 0;

void solve() {
    cin >> n;sum = 0;
    for (int i = 1; i <= n;i++) cin >> a[i], sum += a[i];
    long long mx = sum-1;
    for (int i = 1; i < n; i++) {
        f[i] = max(f[i-1], 0ll) + a[i];
        mx = max(mx, f[i]);
    }
    for (int i = 2; i <= n; i++) {
        g[i] = max(g[i-1], 0ll) + a[i];
        mx = max(mx, g[i]);
    }
    if (mx < sum) cout<<"YES"<<endl;
    else cout << "NO" << endl;
}
int main() {
    ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) solve();
}