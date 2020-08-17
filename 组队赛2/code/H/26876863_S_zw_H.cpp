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
#define N 2100
#define ms(x, y) memset(x, y, sizeof x)
#define INF 0x3f3f3f3f
//ll mod = 12;
using namespace std;
ll cases;
int main()
{
    scanf("%lld", &cases);
    for (ll i = 1; i <= cases;i++){
        ll n;
        scanf("%lld", &n);
        ll b = n + 1;
        ll a = b ^ (n * b);
        printf("%lld\n", a);
    }
        return 0;
}