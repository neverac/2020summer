#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int n,k;
    int ans=0;
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++)
    {
        int w;
        scanf("%d",&w);
        if(w%k==0)
        {
            ans+=w/k;
        }
        else
        {
            ans+=w/k+1;
        }
    }

    if(ans&1)
        printf("%d\n",ans/2+1);
    else
        printf("%d\n",ans/2);
    return 0;
}
