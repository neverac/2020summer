#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[20][505];
int tmp[505];
int n, m;
int ans = m+1;

void dfs(int x, int res) {
    if (x > m) {
        for (int i = 1; i <= n; i++) if (!tmp[i]) return;
        ans = min(ans, res);
        return ;
    }
    dfs(x + 1, res);
    int cnt[505];
    for (int i = 1; i <= n; i++) {
        cnt[i] = tmp[i];
        tmp[i] = max(tmp[i], s[x][i] - '0');
    }
    dfs(x + 1, res + 1);
    for (int i = 1; i <= n;i++) tmp[i] = cnt[i];
}
        

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        scanf("%s", s[i] + 1);
    }
    memset(tmp, 0, sizeof(tmp));
    ans = m + 1;
    dfs(1, 0);
    if (ans > m) puts("-1");
    else cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
       solve();
    }
}