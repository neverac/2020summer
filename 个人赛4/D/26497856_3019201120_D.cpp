#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int N=200200;
int sum;

int ys(int x,int y)
{
    int temp;
    temp=max(x,y);
    x=min(x,y);
    y=temp;
    while(y!=x)
    {
        temp=y-x;
        y=max(x,temp);
        x=min(x,temp);
    }
    return x;
}
int main()
{
    int t,a,b;
    cin>>t;
    int T=1;
    int n;
    while(t--)
    {
        scanf("%d%d%d",&n,&a,&b);
        {
            if(n==2) sum=2;
            else
            {
                int zdg=ys(a,b);
                if(zdg>1)
                {
                    if((n/zdg-2)%2) sum=1;
                    else sum=2;
                }
                else
                {
                    if(n%2) sum=1;
                    else sum=2;
                }
            }
        }
        if(sum==2)
            printf("Case #%d: Iaka\n",T++);
        else 
            printf("Case #%d: Yuwgna\n",T++);
    }
    
}