#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<cmath>
using namespace std;
char s[1005][1005];
vector<int>v[1005],vv[1005];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s[i]+1);
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(s[i][j]=='1')
                v[i].push_back(j);
            if(s[i][j]=='2')
                vv[i].push_back(j);
        }
    
    int ans=1000000000;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            int tt=0,ttt=0;
            int minl=1000000;
            while(tt<v[i].size()&&ttt<vv[j].size())
            {
                if(v[i][tt]<=vv[j][ttt])
                {
                    minl=min(minl,vv[j][ttt]-v[i][tt]);
                    tt++;
                }
                else
                {
                    minl=min(minl,v[i][tt]-vv[j][ttt]);
                    ttt++;
                }
            }
            ans=min(ans,abs(i-j)+minl+1);
//            printf("%d %d %d\n",i,j,abs(i-j)+minl+1);
        }
    printf("%d\n",ans);
    return 0;
}
