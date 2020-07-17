#include<cstdio>
#include<algorithm>
#include<cstring>
#define N 100100

using namespace std;

long long g[N];
long long b[N];

int main()
{
    int i,j;
    int n,m;
    long long ans=0;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
        scanf("%d",b+i);
    for(i=0;i<m;i++)
        scanf("%d",g+i);
    sort(b,b+n);
    sort(g,g+m);
    if(b[n-1]>g[0])
    {
        printf("-1\n");
        return 0;
    }
    for(i=0;i<n;i++)
        ans+=b[i];
    ans*=m;
    for(i=1;i<m;i++)
        ans+=g[i]-b[n-1];
    if(g[0]!=b[n-1])
        ans+=g[0]-b[n-2];
    printf("%lld\n",ans);
    return 0;
}

