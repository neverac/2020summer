#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#define ll long long
using namespace std;
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
ll cnt[110][110][11];
ll m[110][110][11];
ll c;
inline ll cal(int x, int y, int t){
    ll ret = 0;
    for(int i = 0; i <= c; i++){
        ret += ((i + t) % (c + 1)) * (cnt[x][y][i]);
    }
    return ret;
}
int main(){
    ll n = readll(), q = readll();
    c = readll();
    for(int i = 1; i <= 100; i++)
    for(int j = 1; j <= 100; j++)
    for(int k = 0; k <= c; k++){
        m[i][j][k] = 0;
    }
    for(int i = 0; i <= 100; i++)
    for(int j = 0; j <= 100; j++)
    for(int k = 0; k <= c; k++){
        cnt[i][j][k] = 0;
    }
    for(int i = 1; i <= n; i++){
        int x = readint(), y = readint(), s = readint();
        ++m[x][y][s];
    }
    for(int i = 1; i <= 100; i++)
    for(int j = 1; j <= 100; j++)
    for(int k = 0; k <= c; k++){
        cnt[i][j][k] = cnt[i - 1][j][k] + cnt[i][j - 1][k] - cnt[i - 1][j - 1][k] + m[i][j][k];
    }
    for(int i = 1; i <= q; i++){
        int t = readint();
        int x1 = readint(), y1 = readint();
        int x2 = readint(), y2 = readint();
        ll ans = cal(x2, y2, t) - cal(x2, y1 - 1, t) - cal(x1 - 1, y2, t) + cal(x1 - 1, y1 - 1, t);
        printf("%lld\n", ans);
    }
    return 0;
}