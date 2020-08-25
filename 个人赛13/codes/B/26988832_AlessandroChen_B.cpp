#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
using namespace std;

#define int long long
int t, x, y, z;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> t; double ans = 0xfffffff;
  while (t --) {
    cin >> x >> y >> z;
    double dist = sqrt(x * x + y * y + z * z);
    ans = min(ans, dist);
  }
  cout << fixed << setprecision(3) << ans;
}