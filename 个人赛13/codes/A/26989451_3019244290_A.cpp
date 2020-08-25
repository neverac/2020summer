#include <iostream>
#include <stdio.h>
#include<cmath>
#include<cctype>
#include<cstdio>
#include <algorithm>
#include <string.h>
#include <string>
#include<math.h>
#include<map>
#include<unordered_map>
#define Maxn 100000007
#define ll long long

using namespace std;

int main() {
    int t;
    scanf("%d",&t);
    while(t--){
    ll  n, m, x, y;
    scanf("%lld%lld%lld%lld", &n, &m, &x, &y);
    ll ans=min(((m-1)*y+n)/x,m);
    printf("%lld\n", ans);
    }
    return 0;
}
