#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define N 100100

using namespace std;

int n,m;
int gcd(int a,int b)
{
    int c=b;
    while(c)
    {
        c=a%b;
        a=b;
        b=c;
    }
    return a;
}

int main()
{
    int t,a,b;
    int i;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
        scanf("%d%d%d",&n,&a,&b);
        int tmp = gcd(a,b);
        printf("Case #%d: ",i);
        if(n/tmp%2)
        {
            printf("Yuwgna\n");
        }
        else
        {
            printf("Iaka\n");
        }
    }
    return 0;
}
