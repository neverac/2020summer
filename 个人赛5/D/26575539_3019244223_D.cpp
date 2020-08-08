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
using namespace std;
int main()
{  
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        if(n>k)
            cout<<k<<endl;
        else 
        {
            long long sum=k+k/(n-1);
            if(k%(n-1)==0)
                sum--;
            cout<<sum<<endl;

        }

    }       

   
   //system("pause");
    return 0;
}