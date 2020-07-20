#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

/*int main()
{
    int T;
    cin >>T;
    double x1,x2,x3,y1,y2,y3;
    while(T--){
        cin >>x1>>y1>>x2>>y2>>x3>>y3;
        double t1=x3-x1,t2=x3-x2,t3=x2-x1;
        double k1=(y2-y1)/(double(3)*pow(t3,2));
        double k2=(2*y1-y2-y3)/double(2);
        double k3=(y2-y1)/double(3);
        cout<<fixed<<setprecision(2)<<k1*pow(t1,3)+k2*t2-k3*t3<<endl;
    }
    return 0;
}*/

/*
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int m,n,ans,cnt,biggest; //变量比较乱，慢慢领悟(*^__^*) 嘻嘻……
bool flag[100][100],mark[100][100][4];
int map[105][105];
int wayr[4]={0,1,0,-1},wayc[4]={1,0,-1,0}; //此方向不可改，( ⊙o⊙ )千真万确
bool check(int a,int b,int x) //判断函数，一次性囊括所有判断(包括剪枝)，~\(≧▽≦)/~啦啦啦
{
    if(a<m&&b<n&&a>=0&&b>=0&&mark[a][b][x]&&!flag[a][b]) return 1;
    return 0;
}
void dfs(int r,int c) //深搜函数，内部构造简单，~O(∩_∩)O~
{
    for(int i=0;i<4;i++)
        if(check(r+wayr[i],c+wayc[i],i))
        {
            flag[r+wayr[i]][c+wayc[i]]=1;
            cnt++;
            dfs(r+wayr[i],c+wayc[i]);
        }
}
int main()
{
    scanf("%d%d",&m,&n);
    for(int i=0;i<m;i++) //输入并构造"城堡"，别捉急，慢慢看，╰(￣▽￣)╭
        for(int j=0;j<n;j++)
        {
            scanf("%d",&map[i][j]);
            if(!(map[i][j]&1)) mark[i][j][0]=1;
            if(!(map[i][j]&2)) mark[i][j][1]=1;
            if(!(map[i][j]&4)) mark[i][j][2]=1;
            if(!(map[i][j]&8)) mark[i][j][3]=1;
        }
    for(int i=0;i<m;i++) //开始运算，d=====(￣▽￣*)b
        for(int j=0;j<n;j++)
            if(!flag[i][j])
            {
                flag[i][j]=1;
                cnt=1;
                dfs(i,j);
                if(cnt>biggest) biggest=cnt; //找最大，(～￣▽￣)～
                ans++;
            }
    printf("%d\n%d\n",ans,biggest); //♪(^∇^*)，AC啦，ㄟ(≧◇≦)ㄏ
}*/

int main()
{
    int n, k;
    cin >>n>>k;
    int *p = new int[n];
    for(int i=0;i<n;i++){
        p[i] = i+1;
    }
    int x=0;
    bool judge = true;
    for(int i=k;i>=0;i--){
        cout<<p[x]<<' ';
        if(judge){
            x += i;
        }
        else{
            x -= i;
        }
        judge = !judge;
    }
    for(int i=k+1;i<n;i++){
        cout<<p[i]<<' ';
    }
    cout <<endl;
    delete []p;
    return 0;
}
