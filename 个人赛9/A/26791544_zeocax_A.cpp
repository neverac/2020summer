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
ll a[200100];
int main(){
    int n = readint();
    for(int i = 1; i <= 2 * n; i++)
        a[i] = readll();
    sort(a + 1, a + 2 * n + 1);
    ll ans = (a[n] - a[1]) * (a[2 * n] - a [n + 1]);
    for(int i = n + 1; i <= 2 * n - 1; i++){
        ans = min(ans, (a[i] - a[i - n + 1]) * (a[2 * n] - a[1]));
    }
    printf("%lld", ans);
    return 0;
}