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

struct qwq
{
    
};
bool cmp(qwq q,qwq w)
{
    
}


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll ans;
        ans=(n*(n+1))^(n+1);
        cout<<ans<<endl;
    }

    
    
        

   // system("pause");
    return 0;
}