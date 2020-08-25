#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define LL long long
using namespace std;

LL n,m,x,y,ans;

int T;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld%lld%lld",&n,&m,&x,&y);
        if(x<=y) printf("%lld\n",m);
        else
        {
            ans= (n+(m-1)*y)/x;
            if(ans>m) ans = m;
            printf("%lld\n",ans);
        }
    }

	return 0;
}
