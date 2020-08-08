#include<stdio.h>
#include<iostream>
using namespace std;
long long int f[105][105][15];
int main()
{
    int n,q,c;
    scanf("%d%d%d",&n,&q,&c);
//     printf("www\n");
    for(int i=1;i<=n;i++)
    {
        int x,y,s;
        scanf("%d%d%d",&x,&y,&s);
        for(int j=0;j<=c;j++)//求出在每个时刻的数值
        {
            f[x][y][j]+=(s+j)%(c+1);
        }
    }
    
   
    for(int k=0;k<=c;k++)
    {
        for(int i=1;i<=100;i++)
        {
            for(int j=1;j<=100;j++)
            {
                f[i][j][k]=f[i][j][k]+f[i-1][j][k]+f[i][j-1][k]-f[i-1][j-1][k];//在这个点的值等于这个点的
            }
        }
    }

    
    for(int i=0;i<q;i++)
    {
        int t,x1,y1,x2,y2;
        scanf("%d%d%d%d%d",&t,&x1,&y1,&x2,&y2);
        int cc=t%(c+1);
        printf("%lld\n",f[x2][y2][cc]-f[x2][y1-1][cc]-f[x1-1][y2][cc]+f[x1-1][y1-1][cc]);
    }
    
    return 0;
}