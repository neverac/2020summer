#include<iostream>
#include<algorithm>
using namespace std;
long long a[100010],b[100010];
long long dp[2][100010];
int main(){
    int n;
    long long ans;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&b[i]);
    }
    for(int i=1;i<=n;i++){
        dp[0][i]=max(dp[0][i-1],dp[1][i-1]+b[i]);
        dp[1][i]=max(dp[1][i-1],dp[0][i-1]+a[i]);  
    }
    ans = max(dp[0][n],dp[1][n]);
    cout<< ans <<endl;
    return 0;
}