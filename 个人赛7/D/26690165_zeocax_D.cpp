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
//          1,000,000,000,000,000
// 3 ^ 32 = 1,853,020,188,851,841
// 5 ^ 22 = 2,384,185,791,015,625
// 7 ^ 18 = 1,628,413,597,910,449
ll pre[33][23][19];
ll ans[33][23][19];
int main()
{
    memset(pre, 0, sizeof pre);
    memset(ans, 0, sizeof ans);
    pre[0][0][0] = 1;
    for (ll i = 0; i <= 32; i++)
        for (ll j = 0; j <= 22; j++)
            for (ll k = 0; k <= 18; k++)
            {
                if (i + j + k == 0)
                    continue;
                if (k && pre[i][j][k - 1])
                {
                    pre[i][j][k] = pre[i][j][k - 1] * 7;
                }
                else if (j && pre[i][j - 1][k])
                {
                    pre[i][j][k] = pre[i][j - 1][k] * 5;
                }
                else
                {
                    pre[i][j][k] = pre[i - 1][j][k] * 3;
                }
            }
    ans[0][0][0] = 1;
    for (ll i = 0; i <= 32; i++)
        for (ll j = 0; j <= 22; j++)
            for (ll k = 0; k <= 18; k++)
            {
                if (i + j + k == 0)
                    continue;
                if (k && ans[i][j][k - 1])
                {
                    ans[i][j][k] = ans[i][j][k - 1];
                    for (ll ti = 0; ti <= i; ti++)
                        for (ll tj = 0; tj <= j; tj++)
                        {
                            ans[i][j][k] += pre[ti][tj][k];
                        }
                }
                else if (j && ans[i][j - 1][k])
                {
                    ans[i][j][k] = ans[i][j - 1][k];
                    for (ll ti = 0; ti <= i; ti++)
                        for (ll tk = 0; tk <= k; tk++)
                        {
                            ans[i][j][k] += pre[ti][j][tk];
                        }
                }
                else
                {
                    ans[i][j][k] = ans[i - 1][j][k];
                    for (ll tj = 0; tj <= j; tj++)
                        for (ll tk = 0; tk <= k; tk++)
                        {
                            ans[i][j][k] += pre[i][tj][tk];
                        }
                }
            }
    int N = readint();
    while (N--)
    {
        ll A = readll();
        while (A % 2 == 0)
            A /= 2;
        int cnt3 = 0, cnt5 = 0, cnt7 = 0;
        while(A % 3 == 0){
            ++cnt3;
            A /= 3;
        }
        while(A % 5 == 0){
            ++cnt5;
            A /= 5;
        }
        while(A % 7 == 0){
            ++cnt7;
            A /= 7;
        }
        printf("%lld\n", ans[cnt3][cnt5][cnt7]);
    }
    return 0;
}