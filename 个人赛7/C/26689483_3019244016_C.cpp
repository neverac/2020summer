#include <bits/stdc++.h>
using namespace std;
int a[1005], b[1005];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);
    int j = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] < b[j]) continue;
        while (j <= n && a[i] > b[j]) j++;
        if (j > n) {
            ans = n - i + 1;
            break;
        }
    }
    if (j <= n) ans = n - j + 1;
    cout << ans << endl;}
