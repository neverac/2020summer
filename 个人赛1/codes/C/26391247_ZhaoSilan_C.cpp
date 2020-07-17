#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
int a[100005];
int ans[100005];
bool vis[100005];
int pp[100005];
int t,n;

int solve()
{
    int tt=0;
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            tt=i;
            break;
        }
    }
    return tt;
}

int main()
{
    
    scanf("%d",&t);
    while(t--)
    {
        
        bool flag=0;
        
        scanf("%d",&n);
        
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            vis[i]=0;
            ans[i]=0;
        }
        vis[n]=0;
        ans[n]=0;
        ans[0]=a[0];
        vis[a[0]]=1;
        for(int i=1;i<n;i++)
        {
            if(a[i]>a[i-1])
            {
                ans[i]=a[i];
                vis[a[i]]=1;
            }
        }
        int num=0;
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                pp[num++]=i;
            }
        }
        int t=0;
        for(int i=0;i<n;i++)
        {
            
            if(ans[i]==0)
            {
                
                ans[i]=pp[t++];
                
            }
        }
       
        int maxl=ans[0];
        
        for(int i=1;i<n;i++)
        {
            maxl=max(maxl,ans[i]);
            if(maxl!=a[i])
            {
                flag=1;
                break;
            }
        }
        if(flag)
            printf("-1\n");
        else
        {
            for(int i=0;i<n-1;i++)
                printf("%d ",ans[i]);
            printf("%d\n",ans[n-1]);
        }
            printf("\n");
    }
    return 0;
}