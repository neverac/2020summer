#include<bits/stdc++.h>
using namespace std;
#define N 200010
typedef long long LL;
LL a[N], n;
void init(){
    cin>>n;
    for(int i = 1; i <= n * 2; i++) scanf("%lld", &a[i]);
    return ;
}
void solve(){
    LL ans = LONG_LONG_MAX;
    sort(a + 1, a + 1 + n * 2);
    for(int i = 1; i + n - 1 < n * 2; i++){
        LL mina, minb, maxa, maxb;
        if(i == 1){
            mina = a[i], maxa = a[n], minb = a[n + 1], maxb = a[n * 2];
        }
        else{
            mina = a[i], maxa = a[n + i - 1], minb = a[1], maxb = a[n * 2];
        }
        ans = min(ans, (maxa - mina) * (maxb - minb));
    }
    cout<<ans<<endl;
    return ;
}
int main(){
    init();
    solve();
    return 0;
}