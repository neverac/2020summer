#include<bits/stdc++.h>

using namespace std;

int f[5005][5005],D[5005][5005],n,v[5005];

bool com(const int &a,const int &b)
{
    return a>b;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&v[i]);
    sort(v+1,v+1+n);
    if(n==1)
    {
        printf("1\n");
        return 0;
    }
    if(n==2)
    {
        printf("2\n");
        return 0;
    }
    int ans=0;
    f[2][1]=2;
    D[2][1]=v[2]-v[1];
    ans=2;
    for(int i=3;i<=n;i++)
    {
        D[i][1]=v[i]-v[1];
        f[i][1]=2;
        for(int j=2;j<=i-1;j++)
        {
            int d=v[i]-v[j];
            D[i][j]=d;
            int k=lower_bound(D[j]+1,D[j]+j,d,com)-D[j];
            if(D[j][k]==d)f[i][j]=f[j][k]+1;
            else f[i][j]=2;
            ans=max(f[i][j],ans);
        }
    }
    printf("%d\n",ans);
    return 0;
}