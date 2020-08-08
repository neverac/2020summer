#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

string s;
int cnt[20], n;

void solve() {
    cin >> s;
    n = s.size();
    for (int i = 0; i <= 9; i++) cnt[i] = 0;
    int mx = 1;
    for (int i = 0; i < n; i++) cnt[s[i] - '0']++;
    for (int i = 0; i <= 9; i++) mx = max(cnt[i], mx);
    for (int i = 0; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            int f = 0, g = 0;
            if (i == j) continue;
            for (int k = 0; k < n; k++) {
                if (s[k] == i + '0') g = f + 1;
                if (s[k] == j + '0' && g != 0) f = g + 1;
            }
            mx = max(mx, f);
        }
    }
    cout << n-mx << endl;
}


int main() {
    int t;
    ios::sync_with_stdio(0);
    cin >> t;
    while (t--) solve();
}