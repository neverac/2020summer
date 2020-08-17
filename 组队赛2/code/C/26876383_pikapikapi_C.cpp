#include<stdio.h>
#include<iostream>
using namespace std;
int a[105];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    bool flag=0;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            for(int k=j+1;k<n;k++)
            {
                if((a[i]-a[j])%a[k]!=0||(a[i]-a[k])%a[j]!=0||(a[j]-a[k])%a[i]!=0)
                {
                    flag=1;
                    break;
                }
            }
    if(flag)
    {
        printf("no\n");
    }
    else
    {
        printf("yes\n");
    }
    return 0;
}
