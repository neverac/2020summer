#include<stdio.h>
#include<iostream>
using namespace std;
int cnt[100005];
int main()
{
    int n;
    scanf("%d",&n);
    long long int s=0;
    for(int i=0;i<n;i++)
    {
        int x;
        scanf("%d",&x);
        cnt[x]++;
        s+=x;
    }
    int q;
    scanf("%d",&q);
    
    for(int i=0;i<q;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        cnt[b]+=cnt[a];
        s=s+(b-a)*cnt[a];
        cnt[a]=0;
        printf("%lld\n",s);
    }
    return 0;
}

