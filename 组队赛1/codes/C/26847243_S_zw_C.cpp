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
#define N 550000
#define ms(x, y) memset(x, y, sizeof x)
#define INF 0x3f3f3f3f
using namespace std;

ll r, s, p;
struct passager{
    ll i, j;
    ll dis;
    passager(ll i,ll j){
        dis = r - i + 1;
        if(j <= s){
            dis += (s + 1) - j;
        }else{
            dis += j - s;
        }
    };
    passager(){}
    bool operator<(const passager&p)const{
        return dis < p.dis;
    }
}passes[N];

int main()
{
    scanf("%lld %lld %lld", &r, &s, &p);
    for (ll i = 1; i <= p;i++){
        ll u, v;
        scanf("%lld %lld", &u, &v);
        passes[i] = passager(u, v);
    }
    sort(passes + 1, passes + 1 + p);
    ll ans = 0;
    for (ll i = 1; i <= p; i++){
        ans = max(ans, passes[i].dis + p - i + 1);
    }
    if(ans > 0){
        ans--;
    }
    printf("%lld\n", ans);
    return 0;
}