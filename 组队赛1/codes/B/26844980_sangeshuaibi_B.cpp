#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#define ll long long
using namespace std;
const int int_inf = 0x3f3f3f3f;
inline int readint()
{
    int ret = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return ret;
}
inline ll readll()
{
    ll ret = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return ret;
}
int v[5100];
int main()
{
    int n = readint();
    for (int i = 1; i <= n; i++)
        v[i] = readint();
    sort(v + 1, v + n + 1);
    int ans = 2;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            int dif = v[j] - v[i];
            int cur = j;
            int cnt = 2;
            while (cur < n)
            {
                int idx = lower_bound(v + cur + 1, v + n + 1, v[cur] + dif) - v;
                if (idx == n + 1)
                    break;
                if (v[idx] != v[cur] + dif)
                    break;
                cur = idx;
                ++cnt;
            }
            ans = max(ans, cnt);
        }
    printf("%d", ans);
    return 0;
}