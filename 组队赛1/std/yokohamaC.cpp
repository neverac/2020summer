#include<bits/stdc++.h>

using namespace std;

int p[500005], out_order[500005], ans, pos[505][1005];
int r, s, P;

int main()
{
    scanf("%d%d%d", &r, &s, &P);
    for (int i=1;i<=P;i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        pos[a][b]=1;
    }
    for (int i=r;i>=1;i--)
    {
        int org=r-i+1;
        for (int j=s;j>=1;j--)
        {
            org++;
            if (!pos[i][j])continue;
            while (out_order[org])org++;
            out_order[org]=1;
            ans=max(ans, org);
        }
        org=r-i+1;
        for (int j=s+1;j<=2*s;j++)
        {
            org++;
            if (pos[i][j]==0)continue;
            while (out_order[org])org++;
            out_order[org]=1;
            ans=max(ans, org);
        }
    }
    printf("%d\n", ans);
    return 0;
}