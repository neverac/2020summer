#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn =2e6+100;

int n;

long long a[maxn];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=2*n;i++)
    {
        scanf("%lld",&a[i]);
    }
    int m = n*2;
    sort(a+1,a+1+m);
    long long ans = (a[n]-a[1])*(a[2*n]-a[n+1]);
    for(int i=2;i<=n;i++)
    {
        ans= min(ans,(a[n+i-1]-a[i])*(a[2*n]-a[1]));
    }
    printf("%lld\n", ans);
    return 0;
}