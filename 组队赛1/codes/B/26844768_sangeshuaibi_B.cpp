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
vector<int>v;
int main()
{
    int n = readint();
    for (int i = 0; i < n; i++){
        v.push_back(readint());
    }
    sort(v.begin(), v.end());
    int ans = 2;
    for(int i = n - 1; i >= 0; i--)
    for(int j = i - 1; j >= 0; j--)
        {
            int dif = v[i] - v[j];
            int cur = j;
            int cnt = 2;
            while (cur > 0)
            {
                int idx = lower_bound(v.begin(), v.end(), v[cur] - dif) - v.begin();
                if (idx == n)
                    break;
                if (v[idx] != v[cur] - dif)
                    break;
                cur = idx;
                ++cnt;
            }
            ans = max(ans, cnt);
        }
    printf("%d", ans);
    return 0;
}