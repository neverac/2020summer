#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<string.h>
#include<time.h>
#include<queue>
#include<stack>
using namespace std;
int sum[105][105][15];
int main()
{  
    int n,q,c;
    cin>>n>>q>>c;
    memset(sum,0,sizeof(sum));
    int x,y,z;
    for(int i=0;i<n;++i)
    {
        scanf("%d%d%d",&x,&y,&z);
        sum[x][y][z]++;
    }
    for(int i=1;i<=100;++i)
    {
        for(int j=1;j<=100;++j)
        {
            for(int k=0;k<=c;++k)
                sum[i][j][k]=sum[i][j][k]+(sum[i-1][j][k]+sum[i][j-1][k]-sum[i-1][j-1][k]);
        }
    }
    int x1,x2,y1,y2,ts;
    for(int i=0;i<q;++i)
    {
        scanf("%d%d%d%d%d",&ts,&x1,&y1,&x2,&y2);
        int res=0;
        for(int j=0;j<=c;++j)
        {
            int aa=(ts+j)%(c+1);
            res = res + aa*(sum[x2][y2][j]+sum[x1-1][y1-1][j]-sum[x1-1][y2][j]-sum[x2][y1-1][j]);
        }
        cout<<res<<endl;
    }
    
 
    //system("pause");
    return 0;
}

