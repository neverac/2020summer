#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int n,a[1000],sum;

int f[1000];

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),f[i]=a[i],f[i]+=f[i-1];
    int sum = 360,res=0,ans=360;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            res =f[j] -f[i-1];
            int res1 = 360 - res;
            ans = min(ans,abs(res1-res));
        }
    }
    cout<<ans<<endl;
    return 0;
}