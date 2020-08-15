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

int dp[5005][5005];
int x[5005];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>x[i];
    int maxx=0;
    sort(x+1,x+1+n);
    for(int i=1;i<=n;++i)
    {
        int l=i-1;
        for(int j=i+1;j<=n;++j)
        {
            dp[i][j]=2;
            while(l>=1 && x[j]-x[i]>x[i]-x[l])
                l--;
            if(l>=1&&x[j]-x[i]==x[i]-x[l])
                dp[i][j]=max(dp[i][j],dp[l][i]+1);
            maxx=max(maxx,dp[i][j]);
        }
    }
    cout<<maxx<<endl;

    //system("pause");
    return 0;
}