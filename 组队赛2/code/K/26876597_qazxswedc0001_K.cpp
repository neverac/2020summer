#include <bits/stdc++.h>
using namespace std;
const int N = 10000 + 5;
typedef long long ll;
priority_queue<int, vector<int>, greater<int>> pq;
int n;
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        while (!pq.empty()) pq.pop();
        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            int x;
            scanf("%d", &x);
            pq.push(x);
        }
        while (pq.size() >= 2) {
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            ans += a + b;
            pq.push(a + b);
        }
        printf("%lld\n", ans);
    }
    return 0;
}