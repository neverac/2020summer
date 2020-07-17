#include <bits/stdc++.h>

using namespace std;
const int Maxn = 1e5 + 10;
int a[Maxn], n,q;
int main() {
//#define LOCAL
#ifdef LOCAL
    freopen("/Users/ttjy/Desktop/in.txt", "r", stdin);
#endif
    cin >> n;
    int ai;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &ai);
        a[ai]++;
        sum += ai;
    }
    cin >> q;
    while (q--) {
        int b, c;
        scanf("%d%d", &b, &c);
        sum +=a[b]* c-a[b]* b;
        a[c] += a[b];
        a[b] = 0;

        cout << sum << endl;
    }
    return 0;
}