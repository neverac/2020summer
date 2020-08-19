#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5 + 100;
int n, a[maxn];
const int maxbit = 32;
int bit[maxbit];

int solve(int l, int r, int len) {

    int flag = 1 << len, f = -1;

    if (len < 0)
        return 0;

    for (int i = l; i < r; i++)
        if (a[i] & flag) {
            f = i;
            break;
        }

    if (f == -1 || f == l) return solve(l, r, len - 1);
    int res = min(solve(l, f, len - 1), solve(f, r, len));
    return flag | res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    //    for (int i = 0; i <= tot; i++)cout << bit[i] << ' ';
//    cout << endl;
    sort(a, a + n);
    int ans = solve(0, n, 30);
    cout << ans << endl;

    return 0;
}