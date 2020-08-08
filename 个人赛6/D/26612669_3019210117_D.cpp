#include <iostream>
#include <cstring>
using namespace std;
int n,q,c;
int dp[105][105][15];
void cal(){
    for(int i=1;i<=100;i++){
        for(int j=1;j<=100;j++){
            for(int k=0;k<=c;k++){
                dp[i][j][k]+=(dp[i-1][j][k]+dp[i][j-1][k]-dp[i-1][j-1][k]);
            }
        }
    }
}
int getAns(int k,int x1,int y1,int x2,int y2){
    return dp[x2][y2][k]+dp[x1-1][y1-1][k]-dp[x1-1][y2][k]-dp[x2][y1-1][k];
}
int main(){
    int x1,y1,x2,y2,t,k,ans,tem;
    scanf("%d%d%d",&n,&q,&c);
    memset(dp,0,sizeof(dp));
    for(int i=0;i<n;i++){
        scanf("%d%d%d",&x1,&y1,&k);
        dp[x1][y1][k]++;
    }
    cal();
    for(int i=0;i<q;i++){
        scanf("%d%d%d%d%d",&t,&x1,&y1,&x2,&y2);
        ans=0;
        for(int i=0;i<=c;i++){
            tem=(t+i)%(c+1);
            ans+=tem*getAns(i,x1,y1,x2,y2);
        }
        printf("%d\n",ans);
    }
    return 0;
}
