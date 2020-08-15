#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[5005][5005];
int lis[5005];
int n;
int main()
{   cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>lis[i];
    }
    sort(lis,lis+n);
    int ans=-100;
    for(int i=0;i<n;i++)
    {   int k=i-1;
        for(int j=i+1;j<n;j++)
        {
            dp[i][j]=2;
            while(k>=0&&lis[j]-lis[i]>lis[i]-lis[k])
            {
                k--;
            }
            if(k>=0&&lis[j]-lis[i]==lis[i]-lis[k])
            {
                dp[i][j]=dp[k][i]+1;
            }
            ans=max(ans,dp[i][j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
