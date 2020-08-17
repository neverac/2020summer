#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
using namespace std;

int x, vis[20], n, m, num, ans, a[3000], flag;

int f(int x, int now) {
    if (x == n + 1) {
        if (now == num) {
            int res = 0;
            for (int i = 1; i <= n; i++) res |= a[i];
            if (res == ((1 << m) - 1)) return 1;
            else return 0;
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int k, l;
        memset(a, 0, sizeof(a));
        cin >> k >> l;
        if (l >= 2000) {
            cout << -1 << endl;
            continue;
        }
        //1999+k
        //1998e6
        if (k + 1999 >= 1998 * 1000000) {
            cout << -1 << endl;
            continue;
        }
        //l 2--1999
        int x = 2, num = 1999 + k;
        a[1] = -1;
        while (num - 1e6 > 1999 - x) {
            a[x++] = 1e6;
            num -= 1e6;
        }
        for (int i = x + 1; i <= 1999; i++) a[i] = 1, num--;
        a[x] = num;
        cout << 1999 << endl;

        for (int i = 1; i <= 1999; i++)
            cout << a[i] << ' ';

        cout << endl;
    }
}