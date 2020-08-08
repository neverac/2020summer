#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn = 1e5+100;

int f[maxn],a[maxn],b[maxn],n,mx=0;

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),mx =max(mx,a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]),mx =max(mx,b[i]);
    int ans =0 ,l=1,r=1;
    while(l<=n&&r<=n)
    {
        if(a[l]>b[r]) r++;
        else l++;
    }
    ans = max(n-l,n-r);
    ans++;
    printf("%d\n", ans);
    return 0;
}