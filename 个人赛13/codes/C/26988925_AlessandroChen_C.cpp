#include <map>
#include <cstdio>
#include <iostream>
using namespace std;

const int maxn = 1e3 + 10;

#define int long long
int n, m, cnt;
int c[maxn], dp[maxn];
map<string, bool> v;

inline void update(int &x, const int &y) {
  if (y > x) x = y;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  while (m --) {
    string s; cin >> s;
    if (v[s]) continue;
    c[++cnt] = (int)s.length() + 1;
    v[s] = 1;
  }
  for (int i = 1; i <= cnt; ++ i)
    for (int j = n + 1; j >= c[i]; -- j)
    update(dp[j], dp[j - c[i]] + 1);
  cout << dp[n + 1] << endl;
}