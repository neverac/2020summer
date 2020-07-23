#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<string.h>
#include<set>
using namespace std;
int a[100005];
int b[100005];
long long dp[5][100005];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<n+1;++i)
        cin>>a[i];
    for(int i=1;i<n+1;++i)
        cin>>b[i];
    dp[0][1]=b[1];
    dp[1][1]=a[1];
    for(int i=2;i<n+1;++i)
    {
        dp[0][i] = max( dp[1][i-1]+b[i] , dp[0][i-1] );
        dp[1][i] = max( dp[0][i-1]+a[i] , dp[1][i-1] );
    }
    long long result = max(dp[0][n],dp[1][n]);
    cout<<result<<endl;

    
    


    //system("pause");
    return 0;
}