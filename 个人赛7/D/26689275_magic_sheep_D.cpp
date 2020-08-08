#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define LL long long
using namespace std;

const int maxn = 1e5+100;

int n;
int a[maxn],cnt[20];
LL h;
LL mp[10]= {2,3,5,7};


int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&h);
        memset(cnt,0,sizeof(cnt));
        LL cur = h;
        for(int j=0;j<4;j++)
        {
            while(cur&&cur%mp[j]==0)
            {
                cur/=mp[j];
                cnt[j]++;
            }
        }
        LL ans =1;
        for(int j=1;j<4;j++)
        {
            LL res = 1,pos =1;
            for(int l=1;l<=cnt[j];l++)
            {
                pos *=mp[j];
                res +=pos;
            }
            ans*=res;
        }
        printf("%lld\n", ans);
    }
    return 0;
}