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
template <typename T>
inline T read(T arg)
{
    T ret = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9')
    {
        if (c == '-')
            f = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return ret * f;
}
template <typename T>
inline void write(T arg)
{
    if (arg < 0)
    {
        putchar('-');
        arg = ~arg + 1;
    }
    if (arg > 9) write(arg / 10);
    putchar(arg % 10 + '0');
}
const ll mod = 998244353;
ll a[510][510];
ll r[510], c[510];
int main(){
    int n = read(n), m = read(m), k = read(k);
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++){
        a[i][j] = read(a[i][j]) % mod;
    }
    for(int i = 1; i <= k; i++){
        char opt = getchar();
        while(opt != 'r' && opt != 'c')
            opt = getchar();
        int x = read(x);
        ll t = read(t);
        if(opt == 'r')r[x] = t;
        else if(opt == 'c')c[x] = t;
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
        ans = (ans + ((max(r[i], c[j]) % mod) * a[i][j] % mod)) % mod;
    write(ans);
    return 0;
}