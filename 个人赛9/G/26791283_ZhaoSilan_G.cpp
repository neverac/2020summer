#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
bool vis[200005];

struct node
{
    int p,id;
    friend bool operator < (struct node a,struct node b)
    {
        return a.p>b.p;
    }
};
priority_queue<node>q[10];

int p[200005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&p[i]);
    }
    for(int i=1;i<=n;i++)
    {
        int c;
        scanf("%d",&c);
        node t;
        t.p=p[i];
        t.id=i;
        q[c].push(t);
        
    }
    
    for(int i=1;i<=n;i++)
    {
        int c;
        scanf("%d",&c);
        node t;
        t.p=p[i];
        t.id=i;
        q[c].push(t);
    }
    
    int r;
    scanf("%d",&r);
    for(int i=1;i<=r;i++)
    {
        int c;
        scanf("%d",&c);
        bool flag=0;
        while(!q[c].empty())
        {
            node u=q[c].top();
            if(!vis[u.id])
            {
                vis[u.id]=1;
                printf("%d ",u.p);
                flag=1;
                break;
            }
            else
            {
                q[c].pop();
            }
        }
        if(!flag)
        {
            printf("-1 ");
        }
    }
    printf("\n");
    return 0;
}
