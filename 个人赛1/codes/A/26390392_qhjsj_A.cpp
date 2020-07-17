#include <bits/stdc++.h>

using namespace std;

int main() {
//#define LOCAL
#ifdef LOCAL
    freopen("/Users/ttjy/Desktop/in.txt", "r", stdin);
#endif
    int n, k;
    cin >> n >> k;
    int p[1010];
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }
    sort(p, p + n);
    int sum = 0;
    while (k--) {
        sum += p[k];
    }
    cout << sum << endl;
    return 0;
}