
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+100;
int dp[26][maxn];
char s[maxn];
long long ans=0;
int k=0;
void work(){
    int len=strlen(s + 1);
    for(int i=0;i<26;i++){
        int now=0;
        for(int j=1;j<=len;j++){
            if(s[j] - 'a' == i)  now++,dp[i][now]=j;
            if(now == 0) continue;
            if(now>k) ans+= dp[i][now] - dp[i][now - k];
            else ans+=dp[i][now];

        }
    }
}
int main(){
    cin >> k;
    scanf("%s", s + 1);
    work();
    cout << ans << endl;
    return 0;
}

