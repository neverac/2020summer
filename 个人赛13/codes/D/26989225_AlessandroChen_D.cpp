#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;

int fa[maxn];

#define int long long
int n, m, res;
int deg[maxn];
vector<pair<int, int> > edge;

inline void addline(int x, int y) {
  if (x > y) swap(x, y); edge.push_back(pair<int, int>(x, y));
}

inline int getRoot(const int& x) {
  return fa[x] == x ? x : fa[x] = getRoot(fa[x]);
}

inline void joinSet(const int& x, const int& y) {
  fa[getRoot(y)] = getRoot(x);
}

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second == b.second ? a.first < b.first : a.second < b.second;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++ i) fa[i] = i;
  for (int u, v, i = 1; i <= m; ++ i) {
    cin >> u >> v; addline(u, v);
  }
  sort(edge.begin(), edge.end(), cmp);
  for (auto &e : edge) {
    int u = e.first, v = e.second;
    if (getRoot(u) != getRoot(v)) {
      joinSet(u, v), deg[u] ++, deg[v] ++;
    }
  }
  for (int i = 1; i <= n; ++ i) res = max(res, deg[i]);
  cout << res << endl;
}