#include <bits/stdc++.h>
using namespace std;
int op[100005], n, ans[100005], vis[100005];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d", op + i);
            vis[i] = 0;
            ans[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            if (op[i] != op[i - 1]) ans[i] = op[i], vis[op[i]] = 1;
        }
        int now = 1;
        for (int i = 1; i <= n; i++) {
            if (ans[i]) continue;
            while (now <= n && vis[now]) ++now;
            if (now > n || now > op[i]) {
                printf("-1\n");
                goto to;
            }
            ans[i] = now;
            ++now;
        }
        for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
        printf("\n");
    to:;
    }
    return 0;
}