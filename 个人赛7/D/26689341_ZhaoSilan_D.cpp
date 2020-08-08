#include<stdio.h>
#include<iostream>
using namespace std;
long long int x;
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%lld",&x);
        long long int num=1;
        long long int tt=1;
//        long long int cnt=0;
        while(x%3==0)
        {
            x/=3;
            tt*=3;
            num+=tt;
//            cnt++;
        }
        long long int num2=1;
        long long int tt1=1;
//        long long int cnt1=0;
        while(x%5==0)
       {
            x/=5;
            tt1*=5;
            num2+=tt1;
//            cnt1++;
        }
        
        long long int num3=1;
        long long int tt2=1;
//        long long int cnt2=0;
        while(x%7==0)
        {
            x/=7;
            tt2*=7;
            num3+=tt2;
//            cnt2++;
        }
        
//        long long int pp=1;
//        long long int qq=1;
//        long long int ans=0;
//        for(int i=0;i<=cnt1;i++)
//        {
//            for(int j=0;j<=cnt2;j++)
//            {
//                ans+=num*qq*pp
//            }
//        }
//        printf("%lld %lld %lld\n",num,num2,num3);
        printf("%lld\n",num*num2*num3);
    }
    return 0;
}
