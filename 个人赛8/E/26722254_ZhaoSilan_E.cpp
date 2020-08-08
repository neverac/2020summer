#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;
long long int a[100005];
vector<long long int>fs;
long long int f[100005];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        long long int s=0,r=0;
        long long int minn=0,ans=0;
        bool flag=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            s+=a[i];//这是总和
            if(ans<s-minn)
            {
                ans=max(ans,s-minn);
                r=i;
            }
            
            if(minn>=s)
            {
                minn=min(minn,s);
                flag=1;
            }
        }
        
//        printf("%d %d\n",flag,r);
        if(ans>s)
        {
            printf("NO\n");
        }
        else if(ans==s)
        {
            if(!flag&&r==n)
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
