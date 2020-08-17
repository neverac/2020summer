#include<bits/stdc++.h>
using namespace std;
int ans=20,n,m;
int a[20][505];
int st[505];

bool OROK(int x)
{
    for(int i=0;i<n;i++)
    {
       if(st[i]|a[x][i])
           continue;
        else
            return 0;
    }
    return 1;
}

void dfs(int pos,int aa)
{
    if(OROK(pos))
    {
        ans=min(ans,aa);
        return ;
    }
       
   // printf("%d\n",sit);
    int pp[505];
    for(int i=0;i<n;i++)
    {
        pp[i]=st[i];
    }
    
    for(int j=0;j<n;j++)
    {
        st[j]=st[j]|a[pos][j];
    }
    
    for(int i=pos+1;i<=m;i++)
    {
        
        dfs(i,aa+1);
        
    }
    
    for(int i=0;i<n;i++)
    {
        st[i]=pp[i];
    }
    
    return ;
    
}
char s[505];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        ans=20;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%s",s);
            for(int j=0;j<n;j++)
            {
                a[i][j]=s[j]-48;
            }
        }
        
       // printf("111");
        dfs(0,0);
        if(ans!=20)
        {
            printf("%d\n",ans);
        }
        else
        {
            printf("-1\n");
        }
    }
    
    return 0;
    
}
