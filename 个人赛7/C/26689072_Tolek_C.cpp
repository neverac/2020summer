#include <bits/stdc++.h>
using namespace std;
const int N = 10000 + 5;
typedef long long ll;
queue<int> l, r;
int n, a[150], b[150];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i), l.push(i);
    for (int i = 1; i <= n; i++) scanf("%d", b + i), r.push(i);
    while (!l.empty() && !r.empty()) {
        int aa = l.front();
        int bb = r.front();
        if (a[aa] < b[bb]) {
            l.pop();
        } else {
            r.pop();
        }
    }
    printf("%d", l.size() + r.size());
    return 0;
}