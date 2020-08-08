#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long LL;
char a[N];
int t[N], s[N], n, k; 
int head[N], tail[N];

void solve(){
    LL ans = 0;
    for(char c = 'a'; c <= 'z'; c++){
        map<int, int > mp;
        memset(t, 0, sizeof(t));memset(s, 0, sizeof(s));
        int last = 0, cnt = 0;
        for(int i = 1; i <= n; i++){
            if(a[i] == c){
                t[i] = 1;
                ++cnt; mp[cnt] = i;
                head[i] = last;
                last = i;
            }
        }
        cnt = 0;
        for(int i = 1; i <= n; i++){
            if(t[i]) {
                cnt++;
                if(mp[cnt + k]) tail[i] = mp[cnt + k];
                else tail[i] = n + 1;
            }
        }
        for(int i = 1; i <= n; i++){
            if(t[i]){
                LL l = i - head[i];
                LL r = tail[i] - i;
                ans += l * r;
            }
        }
    }
    printf("%lld\n", ans);
    return ;
}

int main(){
    cin>>k;
    scanf("%s", a + 1);
    n = strlen(a + 1);
    solve();
    return 0;
}