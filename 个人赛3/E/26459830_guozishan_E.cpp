#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
long long dp[2][100005];
long long rec[2][100010];
int main()
{
    int n;
    while(cin>>n){
    memset(dp[0],0,sizeof(dp[0]));
    memset(dp[1],0,sizeof(dp[1]));
    for(int i=1;i<=n;i++)
   {
       cin>>rec[0][i];
   }
   for(int i=1;i<=n;i++)
   {
       cin>>rec[1][i];
   }

   for(int i=1;i<=n;i++)
   {
       dp[1][i]=max(dp[0][i-1]+rec[1][i],dp[1][i-1]);
       dp[0][i]=max(dp[1][i-1]+rec[0][i],dp[0][i-1]);
   }
   cout<<max(dp[1][n],dp[0][n])<<endl;
    }
    return 0;
}
