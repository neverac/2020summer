#include <bits/stdc++.h>

using namespace std;
const int Maxn = 1e5 + 10;
int n, m;
int a[Maxn], c[Maxn];
bool vis[Maxn];

//void dfs(int p) {
//    if (p == n) return;
//    else {
//        for (int i = p; i < n; ++i) {
//            swap(c[p], c[i]);
//            dfs(p + 1);
//            swap(c[p], c[i]);
//        }
//    }
//}

int main() {
//#define LOCAL
#ifdef LOCAL
    freopen("/Users/ttjy/Desktop/in.txt", "r", stdin);
#endif
    cin >> m;
    while (m--) {
        memset(a, 0, sizeof(a));
        memset(vis, false, sizeof(vis));
        scanf("%d", &n);
        int flag = true;
        for (int i = 0; i < n; ++i) {
            int b;
            scanf("%d", &b);
            a[i] = b;
            vis[b] = true;
            if (b <= i) {
                flag = false;
            }
        }
        if (flag) {
            int j = 0;
            for (int i = 1; i <= n; ++i) {
                if (!vis[i])
                    c[j++] = i;
            }
//            dfs(0);
            j = 0;
            for (int i = 0; i < n; ++i) {
                if (vis[a[i]]) {
                    cout << a[i] << " ";
                    vis[a[i]] = false;
                } else
                    cout << c[j++] << " ";
            }
        } else {
            cout << -1;
        }
        cout << endl;
    }
    return 0;
}