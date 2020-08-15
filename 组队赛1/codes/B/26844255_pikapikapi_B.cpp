#include <bits/stdc++.h>
using namespace std;
unordered_map<int,int>X;
int x[5005];
int main()
{
    int n,maxn=-1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x[i]);
        X[x[i]]=1;
        maxn=max(x[i],maxn);
    }
    sort(x,x+n);
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            int d=x[j]-x[i];
            int cd=2;
            int tt=x[j];
            while((tt)<=maxn-d&&X.count(tt+d))
            {
                tt+=d;
                cd++;
            }
            if(cd>ans)
                ans=cd;
        }
    }
    printf("%d\n",ans);
    return 0;
}
