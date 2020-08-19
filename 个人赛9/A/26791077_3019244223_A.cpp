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
#define ll  long long
#define ull unsigned long long

ll x[200005];
int main()
{  
    ll n;
    cin>>n;
    for(ll i=1;i<=2*n;++i)
        cin>>x[i];

    sort(x+1,x+2*n+1);

    ll a=x[n]-x[1];
    ll b=x[2*n]-x[n+1];
    ll minn=a*b;
    ll sum;
    b=x[2*n]-x[1];
    for(int i=1;i<=n+1;++i)
    {
        a=x[i+n-1]-x[i];
        sum=a*b;
        minn=min(sum,minn);
    }
    cout<<minn<<endl;

    




    //system("pause");
    return 0;
}

