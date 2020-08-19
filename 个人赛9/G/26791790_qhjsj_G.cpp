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
typedef long long ll;
const int Maxn = 2e5 + 5;

struct Cloth {
    bool has;
    ll p;
    int a, b, no;

    bool operator<(const Cloth &c) const {
        return p > c.p;
    }
} cloth[Maxn];

ll tmp_p[Maxn];
int tmp_a[Maxn], tmp_b[Maxn];
priority_queue<Cloth> q[4];

int main() {
#ifndef ONLINE_JUDGE
    freopen("/Users/ttjy/Desktop/in.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) scanf("%lld", &tmp_p[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &tmp_a[i]);
    for (int i = 0; i < n; ++i) scanf("%d", &tmp_b[i]);
    for (int i = 0; i < n; ++i) {
        cloth[i] = {1, tmp_p[i], tmp_a[i], tmp_b[i], i};
        q[tmp_a[i]].push(cloth[i]);
        q[tmp_b[i]].push(cloth[i]);
    }
    int t;
    cin >> t;
    while (t--) {
        scanf("%d", &n);
        while (q[n].size() && !cloth[q[n].top().no].has)
            q[n].pop();
        if (q[n].empty())cout << -1 << endl;
        else {
            cout << q[n].top().p << endl;
            cloth[q[n].top().no].has = 0;
        }
    }
    return 0;
}

