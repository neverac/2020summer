#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn = 1e6+100;
int f[1010][1010];
char s[1010][1010];
int cnt1,cnt2;
struct node
{
    int x,y,id;
};
node f1[maxn],f2[maxn];
int jump[1010],n,m;
bool cmp(node a,node b)
{
    if(a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s[i]+1);
    }
    int ans= 1e9;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i][j]=='1') f1[++cnt1].x=i,f1[cnt1].y=j,jump[i]++;
            if(s[i][j]=='2') f2[++cnt2].x=i,f2[cnt2].y=j;
            if(s[i][j]=='1'&&s[i-1][j]=='2') ans=2;
            if(s[i][j]=='1'&&s[i][j-1]=='2') ans=2;
            if(s[i][j]=='1'&&s[i+1][j]=='2') ans=2;
            if(s[i][j]=='1'&&s[i][j+1]=='2') ans=2;
        }
    }
    if(ans==2){
        cout<<2<<endl;
        return 0;
    }
    for(int i=1;i<=cnt1;i++)
    {
        for(int j=1;j<=cnt2;j++)
        {
            ans=min(ans,abs(f1[i].x-f2[j].x)+abs(f1[i].y-f2[j].y)+1);
        }
    }
    cout<<ans<<endl;
    return 0;
}