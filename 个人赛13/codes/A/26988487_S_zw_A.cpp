#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector> 
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <set>
#define ll long long
#define N 610000
#define ms(x, y) memset(x, y, sizeof x)
#define INF 0x3f3f3f3f
using namespace std;

int main()
{
    //freopen("data.in", "r", stdin);
    //freopen("my.out", "w", stdout);
    ll cases;
    scanf("%lld", &cases);
    while (cases--)
    {
        ll n, m, x, y;
        scanf("%lld %lld %lld %lld", &n, &m, &x, &y);
        if(y >= x){
            printf("%lld\n", m);
        }
        else{
            ll total = n + (m - 1)*y;
            ll ans = total / x;
            printf("%lld\n", min(ans,m));
        }
    }
    
    return 0;
}