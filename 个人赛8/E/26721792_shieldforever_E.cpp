#include<bits/stdc++.h>
using namespace std;
#define N 100010
typedef long long LL;
LL a[N], f[N], sum;
int n;
void init(){
    scanf("%d", &n);
    sum = 0LL;
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        sum += a[i];
    }
    return ;
}
void solve(){
    LL ans = a[1];
    f[1] = a[1];
    for(int i = 2; i < n; i++){
        f[i] = max(f[i - 1] + a[i], a[i]);
        ans = max(ans, f[i]);
    }
    f[2] = a[2];
    ans = max(ans, f[2]);
    for(int i = 3; i <= n; i++){
        f[i] = max(f[i - 1] + a[i], a[i]);
        ans = max(ans, f[i]);
    }
    if(sum > ans) printf("YES\n");
    else printf("No\n");
    return ;
}
int main(){
    int T;
    cin>>T;
    while(T--){
        init();
        solve();
    }
    return 0;
}