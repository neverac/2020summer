#include <cstdio>
#include <iostream>
using namespace std;

#define int long long
int n, m, x, y, t;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> t;
  while (t --) {
    cin >> n >> m >> x >> y;
    if (y >= x) cout << m << endl;
    else cout << min(m, (n + (m - 1) * y) / x) << endl;
  }
}