#include <iostream>
#include <cmath>
using namespace std;
long long int dp[100005][2],a[100005],b[100005];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lld",a+i);
    }
    for(int i=0;i<n;i++){
        scanf("%lld",b+i);
    }
    for(int i=0;i<n;i++){
        if(i>0){
            dp[i][1]=max(dp[i-1][0]+a[i],dp[i-1][1]);
            dp[i][0]=max(dp[i-1][1]+b[i],dp[i-1][0]);
        }else{
            dp[i][1]=a[i];
            dp[i][0]=b[i];
        }
    }
    printf("%lld",max(dp[n-1][0],dp[n-1][1]));
    return 0;
}