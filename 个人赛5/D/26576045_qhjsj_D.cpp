#include <bits/stdc++.h>

using namespace std;

int main() {
//#define LOCAL
#ifdef LOCAL
    freopen("/Users/ttjy/Desktop/in.txt", "r", stdin);
#endif
    int t, k, n;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        if (k % (n - 1))
            cout << (k / (n - 1) * n + k % (n - 1)) << endl;
        else
            cout << (k / (n - 1) * n + k % (n - 1)) - 1 << endl;
    }
    return 0;
}
