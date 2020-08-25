#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;
typedef long long LL;
string s[1010];
int cnt = 0;
int len[1010];
int main(){
    int M,N;
    scanf("%d%d",&M,&N);
    for(int i = 1;i <= N;i++)cin>>s[i];
    sort(s+1,s+1+N);
    cnt = 1;
    for(int i = 2;i <= N;i++){
        if(s[i] == s[cnt])continue;
        s[++cnt] = s[i];
    }
    for(int i = 1;i <= cnt;i++)len[i] = s[i].length();
    sort(len + 1,len + 1 + cnt);
    int ans = 0;
    if(M < len[1]){
        printf("0\n");
        return 0;
    }
    M -= len[1];
    ans = 1;
    for(int i = 2;i <= cnt;i++){
        if(M - len[i] - 1 < 0)break;
        M -= len[i] + 1;
        ans++;
    }
    printf("%d\n",ans);
    return 0;
}