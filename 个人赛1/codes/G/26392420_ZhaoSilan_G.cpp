#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
long long int b[100005],g[100005];
bool vis[100005];
int main()
{
    long long int n,m;
    scanf("%lld%lld",&n,&m);
    for(long long int i=0;i<n;i++)
    {
        scanf("%lld",&b[i]);
        
    }
    for(long long int i=0;i<m;i++)
    {
        scanf("%lld",&g[i]);
        vis[i]=0;
    }
    
    sort(b,b+n);
    sort(g,g+m);
    
    if(g[0]<b[n-1])
    {
        printf("-1\n");
        return 0;
    }
    
    long long int s=0;
    for(long long int i=1;i<m;i++)
        s+=g[i];
        
    if(g[0]==b[n-1])
    {
        s+=b[n-1];
        
        for(long long int i=n-2;i>=0;i--)
            s+=b[i]*m;
    }
    else
    {
        s+=b[n-1];
        s+=g[0];
        s+=b[n-2]*(m-1);
        for(long long int i=n-3;i>=0;i--)
        s+=b[i]*m;
    }
    printf("%lld\n",s);
    return 0;
}
