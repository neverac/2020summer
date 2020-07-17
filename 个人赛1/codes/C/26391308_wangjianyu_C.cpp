#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int rec[100100];
bool used[100100];

int main()
{
    int n,k,i;
    int a,b,t;
    int ans=0;
    bool flag;
    int canuse;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        b=0;
        memset(used,false,sizeof(used));
        flag=1;
        canuse=1;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a);
            if(!flag) continue;
            if(a>b)
            {
                used[a]=true;
                rec[i]=a;
                if(canuse==a)
                    canuse++;
            }
            else
            {
                while(used[canuse])
                    canuse++;
                if(a<canuse)
                {
                    flag=false;
                    continue;
                }
                rec[i]=canuse;
                used[canuse]=true;
                canuse++;
            }
            b=a;
        }
        if(!flag)
        {
            printf("-1\n");
        }
        else
        {
            for(i=0;i<n-1;i++)
            {
                printf("%d ",rec[i]);
            }
            printf("%d\n",rec[i]);
        }
    }
    return 0;
}
