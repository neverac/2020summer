#include<stdio.h>
#include<iostream>
using namespace std;
typedef long long int ll;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int n,k;
        scanf("%lld%lld",&n,&k);
        long long int l=1,r=2000000000;
        while(l<=r)
        {
            long long int mid=(l+r)/2;
            if(mid-mid/n>=k)
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        printf("%lld\n",r+1);
    }
    return 0;
}
