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
typedef long long  ll;
ll x[200010];

int main()
{  
    int t;
    cin>>t;
    while(t--)
    {
        ll sum,fen,max1,max2;
        int n;
        cin>>n;
        sum=0;
        for(int i=1;i<=n;++i)
        {
            cin>>x[i];
            sum+=x[i];
        }
        fen=x[1];
        max1=x[1];
        for(int i=2;i<=n-1;++i)
        {
            if(fen<=0)
                fen=x[i];
            else 
                fen+=x[i];
            max1=max(max1,fen);
        }
        fen=x[2];
        max2=x[2];
        for(int i=3;i<=n;++i)
        {
            if(fen<=0)
                fen=x[i];
            else 
                fen+=x[i];
            max2=max(max2,fen);
        }
        if(max(max1,max2)>=sum)
            cout<<"NO"<<endl;
        else 
            cout<<"YES"<<endl;
    }



   // system("pause");
    return 0;
}

