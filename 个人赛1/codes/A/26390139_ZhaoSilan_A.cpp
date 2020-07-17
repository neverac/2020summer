#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int p[1005];
int main()
{
    int n;
    int k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
    }
    sort(p,p+n);
    long long int s=0;
    for(int i=0;i<k;i++)
    {
        s+=p[i];
    }
    printf("%lld\n",s);
    return 0;
}
