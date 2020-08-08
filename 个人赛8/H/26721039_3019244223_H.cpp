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
int x[200005];
int l[200005];
int r[200005];
int main()
{  
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>x[i];
        r[i]=1;
        l[i]=1;
    }
    
    int maxx=0;
    for(int i=n-1;i>=1;--i)
    {
        if(x[i]<x[i+1])
            r[i]=r[i+1]+1;
        maxx=max(maxx,r[i]);
    }
    for(int i=2;i<=n;++i)
    {
        if(x[i-1]<x[i])
            l[i]=l[i-1]+1;
         maxx=max(maxx,l[i]);
    }
    for(int i=1;i<=n-2;++i)
    {
        if(x[i]<x[i+2])
            maxx=max(maxx,l[i]+r[i+2]);
    }
    cout<<maxx<<endl;



    //system("pause");
    return 0;
}

