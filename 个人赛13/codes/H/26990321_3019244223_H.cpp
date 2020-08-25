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
#include<set>
#include<cctype>
using namespace std;
#define ll  long long
#define ull unsigned long long
inline int read() {
    char ch = getchar(); int x = 0, f = 1;
    while(ch < '0' || ch > '9') {
        if(ch == '-') f = -1;
        ch = getchar();
    } while('0' <= ch && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    } return x * f;
}




ll x[505][505];
ll R[505];
ll C[505];
ll mod=998244353;
int main()
{
    ll n,m,k;
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            cin>>x[i][j];
            x[i][j]%=mod;
        }
    }

    while(k--)
    {
        char a;
        cin>>a;
        ll b,c;
        cin>>b>>c;
        if(a=='r')
        {
            R[b]=c;
        }
        else 
        {
            C[b]=c;
        }
    }

    ll sum=0;

    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j)
        {
            sum = (sum + ( max(R[i],C[j])%mod*x[i][j]%mod))%mod;
        }
    }
    cout<<sum<<endl;



    
    
        

    //system("pause");
    return 0;
}