#include<stdio.h>
#include<iostream>
using namespace std;
int f[100005];
bool vis[100005];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int num=1;
    f[1]=1;
    int cs=1;
    vis[1]=1;
    for(int i=m;i>=1;i--)
    {
        if(cs&1)
        {
            ++num;
            f[num]=f[num-1]+i;
            vis[f[num]]=1;
        }
        else
        {
            ++num;
            f[num]=f[num-1]-i;
            vis[f[num]]=1;
        }
        cs++;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            ++num;
            f[num]=i;
        }
            
    }
    for(int i=1;i<=n;i++)
    {
        printf("%d ",f[i]);
    }
    return 0;
}
