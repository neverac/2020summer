#include <bits/stdc++.h>

#define ll long long
using namespace std;
const int maxn = 4e5 + 100;
int n, p[maxn], vis[maxn];

int inline read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

struct node {
    int p, num;
} a[maxn], b[maxn], c[maxn];
int cnt1, cnt2, cnt3, now1, now2, now3;

bool cmp(node a, node b) {
    return a.p < b.p;
}

int main() {
    ios:;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    n = read();
    for (int i = 1; i <= n; i++) p[i] = read();
    for (int i = 1; i <= n; i++) {
        int x = read();
        vis[i] = x;
        if (x == 1) a[++cnt1].num = i, a[cnt1].p = p[i];
        if (x == 2) b[++cnt2].num = i, b[cnt2].p = p[i];
        if (x == 3) c[++cnt3].num = i, c[cnt3].p = p[i];
    }

    for (int i = 1; i <= n; i++) {
        int x = read();
        if (vis[i] == x) continue;
        if (x == 1) a[++cnt1].num = i, a[cnt1].p = p[i];
        if (x == 2) b[++cnt2].num = i, b[cnt2].p = p[i];
        if (x == 3) c[++cnt3].num = i, c[cnt3].p = p[i];
    }

    sort(a + 1, a + 1 + cnt1, cmp);
    sort(b + 1, b + 1 + cnt2, cmp);
    sort(c + 1, c + 1 + cnt3, cmp);
    int m;
    m = read();


    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= m; i++) {
        int x;
        x = read();

        if (x == 1) {
            ++now1;
            while (vis[a[now1].num] && now1<=cnt1)++now1;
            if (now1 > cnt1) {
                cout << "-1 ";
                continue;
            }

            vis[a[now1].num] = 1;
            cout << a[now1].p << ' ';
        } else if (x == 2) {
            ++now2;

            while (vis[b[now2].num]&& now2<=cnt2)++now2;
            if (now2 > cnt2) {
                cout << "-1 ";
                continue;
            }
            vis[b[now2].num] = 1;
            cout << b[now2].p << ' ';
        } else if (x == 3) {
            ++now3;

            while (vis[c[now3].num]&& now3<=cnt3)++now3;
            if (now3 > cnt3) {
                cout << "-1 ";
                continue;
            }
            vis[c[now3].num] = 1;
            cout << c[now3].p << ' ';
        }

    }

}