#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int n,k,s,p,t;
    scanf("%d%d%d%d",&k,&n,&s,&p);
    if(n%s==0)
    {
        t=n/s;
    }
    else
    {
        t=n/s+1;
    }
    t*=k;
    if(t%p==0)
    {
        printf("%d\n",t/p);
    }
    else
    {
        printf("%d\n",t/p+1);
    }
    return 0;
}