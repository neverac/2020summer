#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<string.h>
#include<time.h>
#include<queue>
#include<stack>
#include<map>
using namespace std;


int main()
{  
    int T;
    cin>>T;
    while(T--)
    {
        long long n;
        scanf("%lld",&n);
        while(n%2==0)
            n=n/2;
        long long res=1;
        for(int i=3;i<=7;i=i+2)
        {
            long long sum=1;
            long long tem=1;
            while(n%i==0)
            {
                n=n/i;
                tem=tem*i;
                sum=sum+tem;
            }
            res=res*sum;
        }
        printf("%lld\n",res);


    }





 
    //system("pause");
    return 0;
}

