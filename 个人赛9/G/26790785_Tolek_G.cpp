#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 5;
typedef long long ll;
set<ll> ssp[4];
ll p[N];
int a[N], b[N];
int main()
{
    int n, m;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", p + i);
    for (int i = 1; i <= n; i++) scanf("%d", a + i), ssp[a[i]].insert(p[i]);
    for (int i = 1; i <= n; i++) scanf("%d", b + i), ssp[b[i]].insert(p[i]);
    scanf("%d", &m);
    while (m--) {
        int x;
        scanf("%d", &x);
        if (ssp[x].empty()) {
            printf("-1 ");
            continue;
        }
        ll pr = *ssp[x].begin();
        ssp[1].erase(pr), ssp[2].erase(pr), ssp[3].erase(pr);
        printf("%lld ", pr);
    }
    return 0;
}