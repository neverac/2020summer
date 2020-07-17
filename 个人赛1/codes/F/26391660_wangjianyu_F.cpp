#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int num[100100];

int main()
{
    int n,k,i;
    int a,b,q;
    long long t;
    long long total=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a);
        total+=a;
        num[a]++;
    }
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d",&a,&b);
        t=num[a];
        num[a]=0;
        num[b]+=t;
        total+=t*b-t*a;
        printf("%lld\n",total);
    }
    return 0;
}
