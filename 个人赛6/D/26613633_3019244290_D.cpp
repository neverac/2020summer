#include <iostream>
#include <stdio.h>
#include<cmath>
#include<cctype>
#include<cstdio>
#include <algorithm>
#include <string.h>
#include <string>
#include<math.h>
#include<map>
#include<unordered_map>
#define Maxn 105
using namespace std;

int m[Maxn][Maxn][12];
int n,q,c;
int main()
{
    int s,x,y,t,x1,x2,y1,y2;
    scanf("%d%d%d",&n,&q,&c);
    memset(m,0,sizeof(m));
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&x,&y,&s);
        m[x][y][s]++;
    }
    for(int i=1;i<=100;i++)//预处理一下；亮度不同星星的个数
        for(int j=1;j<=100;j++){
           for(int k=0;k<=c;k++)
           m[i][j][k]+=(m[i-1][j][k]+m[i][j-1][k]-m[i-1][j-1][k]);
    }

    for(int i=0;i<q;i++){
        int sum=0;
        scanf("%d%d%d%d%d",&t,&x1,&y1,&x2,&y2);

        for(int i=0;i<=c;i++){

            int num=m[x2][y2][i]+m[x1-1][y1-1][i]-m[x1-1][y2][i]-m[x2][y1-1][i];
            int tt=(t+i)%(c+1);
            sum+=tt*num;
        }
        printf("%d\n",sum);
    }

    return 0;
}
