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

ll n;
ll a[N];
int main()
{
    scanf("%lld", &n);
    for (ll i = 1; i <= 2*n;i++){
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + 1 + 2 * n);
    ll width = INF;
    ll start = 0, end = 0;
    for (ll i = 1; i <= n;i++){
        if(a[i + n-1] - a[i] < width){
            start = i, end = i + n;
            width = a[i + n-1] - a[i];
        }
    }
    ll heigth;
    if(start == 1){
        heigth = a[2 * n] - a[n + 1];
    }else if(start == n+1){
        heigth = a[n] - a[1];
    }
    else{
        heigth = a[2 * n] - a[1];
    }
    ll ans1 = width * heigth;
    ll ans2 = (a[n] - a[1]) * (a[2 * n] - a[n + 1]);
    printf("%lld\n", min(ans1, ans2));
    return 0;
}
