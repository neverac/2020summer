#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int n,pos,cnt;
long long lis[200005];
long long sz[200005];
long long sz2[200005];
int main()
{   cin>>n;
    for(int i=1;i<=n;i++)
    {
        sz[i]=1;
    }
     for(int i=1;i<=n;i++)
    {
        sz2[i]=1;
    }
    for(int i=1;i<=n;i++)
    {
       cin>>lis[i];
    }
    for(int i=2;i<=n;i++)
    {
        if(lis[i]>lis[i-1])
        {
            sz[i]=sz[i-1]+1;
        }
    }
    sz2[n+1]=0;
    for(int i=n;i>=2;i--)
    {
        if(lis[i]>lis[i-1])
        {
            sz2[i-1]=sz2[i]+1;
        }
    }
    long long  maxx=1;
    for(int i=1;i<=n;i++)
    {
        if(sz[i]>maxx)
        {
            maxx=sz[i];
        }
    }
    lis[n+1]=-1;
    for(int i=1;i<=n-2;i++)
    {
        if(lis[i]<lis[i+2])
        {
            maxx=max(maxx,sz[i]+sz2[i+2]);
        }
    }
    cout<<maxx<<endl;
    return 0;
}
