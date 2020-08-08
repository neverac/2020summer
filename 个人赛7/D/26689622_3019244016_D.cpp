#include <bits/stdc++.h>
using namespace std;
int cnt[10];
int p[]={0,2,3,5,7};
long long ans;
long long qpow(long long x, long long y) {
    long long res = 1;
    while (y) {
        if (y & 1) res = res * x;
        x = x * x ;
        y >>= 1;
        }
        return res;
        }


void dfs(int x, long long tmp) {
//cout << x << " " << tmp << endl;
    if (x >= 5) {
        ans += tmp;
        return;
        }
    for (int i = 0; i <= cnt[x]; i++) {
        dfs(x+1, tmp * qpow(p[x] * 1ll, i * 1ll));
        }
        }
int main() {
    int n;
    cin >> n;
    while (n--) {
        long long x;
        memset(cnt, 0, sizeof(cnt));
        cin >> x;
        for (int i = 1; i <= 4; i++) {
            while (x % p[i] == 0) cnt[i]++, x/=p[i];
        }
        ans = 0;
        dfs(2, 1);
        cout << ans << endl;
    }
    
}
        