#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
int a[5005],b[5005];
int vis[5005],r[5005];
vector<int> e[5005];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int num1=0;
    int num2=0;
    
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&a[i],&b[i]);
        r[b[i]]++;
        e[a[i]].push_back(b[i]);
        if(a[i]<b[i])
            num1++;
        else
            num2++;
    }
    bool flag=0;
    for(int i=1;i<=n;i++)
    {
            int po=0;
            for(int j=1;j<=n;j++)
            {
                if(r[j]==0&&vis[j]==0)
                {
                    po=j;
                    break;
                }
            }
        
            vis[po]=1;
        
            if(po==0)//没找到
            {
                flag=1;
                break;
            }
        
            for(int j=0;j<e[po].size();j++)
            {
                r[e[po][j]]--;
            }
    }

    if(flag==1)
    {
        int ans=0;
        if(num1)
        ans++;
        if(num2)
        ans++;
    
        printf("%d\n",ans);
    
        if(ans==2)
            for(int i=0;i<m;i++)
            {
                if(a[i]<b[i])
                    printf("1 ");
                else
                    printf("2 ");
            }
        else
            for(int i=0;i<m;i++)
                printf("1 ");
    }
    else
    {
        printf("1\n");
        for(int i=0;i<m;i++)
               printf("1 ");
    }
    printf("\n");
    return 0;
}
