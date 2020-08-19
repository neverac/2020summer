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
#define ll long long
#define N 210000
#define ms(x, y) memset(x, y, sizeof x)
#define INF 0x3f3f3f3f
//ll mod = 12;
using namespace std;

struct shirt
{
    ll index, price,front,back;
    bool operator<(const shirt &s)const{
        return price < s.price;
    }
}shirts[N];

queue<shirt>S[4];
bool vis[N];
ll n, m;
int main()
{
    scanf("%lld", &n);
    for (ll i = 1; i <= n;i++){
        scanf("%lld", &shirts[i].price);
    }
    for (ll i = 1; i <= n;i++){
        scanf("%lld", &shirts[i].front);
    }
    for (ll i = 1; i <= n;i++){
        scanf("%lld", &shirts[i].back);
    }
    sort(shirts + 1, shirts + 1 + n);
    for (ll i = 1; i <= n;i++){
        shirts[i].index = i;
        S[shirts[i].front].push(shirts[i]);
        S[shirts[i].back].push(shirts[i]);
    }
    scanf("%lld", &m);
    for (ll i = 1; i <= m;i++){
        ll color;
        scanf("%lld", &color);
        while (!S[color].empty() && vis[S[color].front().index])
        {
            S[color].pop();
        }
        if(S[color].empty()){
            printf("-1 ");
            continue;
        }
        printf("%lld ", S[color].front().price);
        vis[S[color].front().index] = 1;
        S[color].pop();
    }
    printf("\n");
    return 0;
}
