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
#define N 22000
#define mid ((l + r) >> 1)
#define lc (rt << 1)
#define rc ((rt << 1) | 1)
#define tree_len (r - l + 1)
#define left_len (mid - l + 1)
#define right_len (r - mid)
#define tozero(x) memset(x, 0, sizeof x);
#define INF 0x3f3f3f3f
const ll mod = 1e5 + 7;
using namespace std;

ll arr[N];
ll n;


ll handle(ll num){
    ll yinzi[10];
    tozero(yinzi);
    while (num%2 == 0)
    {
        num /= 2;
    }
    ll ans = 1;
    for (ll i = 3; i <= 7;i+=2){
        ll tmp = 1;
        ll total = 1;
        while (num%i == 0)
        {
            num /= i;
            tmp *= i;
            yinzi[i]++;
            total += tmp;
        }
        ans *= total;
    }
    return ans;
}

int main()
{
    scanf("%lld", &n);
    ll num;
    for (ll i = 1; i <= n;i++){
        scanf("%lld", &num);
        printf("%lld\n", handle(num));
    }
        return 0;
}