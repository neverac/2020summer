#include<algorithm>
#include<stdio.h>
#include<iostream>
using namespace std;
typedef long long int LL;
long long int a[200005];
int main()
{
    int n;
    scanf("%d",&n);
    long long int sum=0;
    for(int i=0;i<2*n;i++)
    {
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    sort(a,a+2*n);
    
    
    long long int minn=(a[n-1]-a[0])*1LL*(a[2*n-1]-a[n]);
    
    
    for(int i=n;i<2*n-1;i++)
    {
     //   printf("%lld\n",(a[i]-a[i-n+1])*1LL*(a[2*n-1]-a[0]));
        minn=min((a[i]-a[i-n+1])*1LL*(a[2*n-1]-a[0]),minn);
    }
  //  printf("%d\n",maxn);
    printf("%lld\n",minn);
    return 0;
}
