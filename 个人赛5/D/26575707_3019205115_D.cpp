#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int T;
long long n,k;
int main()
{
    scanf("%d",&T);
    while(T--){
       scanf("%d%d",&n,&k);
       long long y=n*k;
       long long x=n-1;
       long long r = y%x;
       if(r==0)
        printf("%lld\n",(y/x)-1);
       else
        printf("%lld\n",y/x);
       /*for(int i=n-1;i>=1;i--){
        if((y-i)%x==0){
            printf("%lld\n",(y-i)/x);
            break;
        }
       }
       cout <<y/x <<endl;*/
    }
    return 0;
}
