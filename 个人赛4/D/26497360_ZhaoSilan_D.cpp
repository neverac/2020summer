#include<stdio.h>
#include<iostream>
using namespace std;
int gcd(int x, int y)
{
     if(y == 0) return x;
     if(x < y)      return gcd(y,x);
     else        return gcd(y, x%y);
}
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        int n,a,b;
        int t;
        scanf("%d%d%d",&n,&a,&b);
        
       
    
            t=n/gcd(a,b);
            if(t&1)
            {
                 printf("Case #%d: Yuwgna\n",i);
            }
            else
            {
                printf("Case #%d: Iaka\n",i);
            }
        
    }
    return 0;
}
