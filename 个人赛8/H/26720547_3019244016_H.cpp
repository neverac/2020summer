#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 2e5 + 100;
int f[N], g[N], a[N], n;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    f[1] = 1;
    g[2] = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] > a[i-1]) f[i] = f[i-1] + 1, g[i] = g[i-1] + 1;
        else f[i] = 1;
        if (a[i] > a[i-2]) g[i] = max(g[i], f[i-2] + 1);
    }
    int mx = 1;
    for (int i = 1; i <= n;i++) mx = max(mx, max(f[i], g[i]));
    cout << mx << endl;
}