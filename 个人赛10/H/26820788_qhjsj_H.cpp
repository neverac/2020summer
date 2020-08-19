#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<cstring>
#include<set>
#include<cmath>
#include<queue>
#include<sstream>
#include<algorithm>

using namespace std;
const int N = 365;
int angle[N], s[N];
int main() {
//#define LOCAL
#ifdef LOCAL
    freopen("/Users/ttjy/Desktop/in.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", angle + i);
        s[i] = s[i - 1] + angle[i];
    }
    int res = 0x3f3f3f3f;
    for (int len = 0; len < n; ++len) {
        for (int l = 1, r; (r = l + len )<= n; ++l) {
            res = min(res, abs(360 - 2*s[r] + 2*s[l - 1]));
        }
    }
    cout << res << endl;
    return 0;
}

