#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
ll a[100100], b[100100];
int cnt[100100];
ll ans = 0;
int main(){
    bool OK = true;
    int n, m; scanf("%d%d", &n, &m);
    ll mx = 0;
    for(int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
        ans += a[i] * m;
        mx = max(mx, a[i]);
        cnt[i] = m - 1;
    }
    sort(a + 1, a + n + 1);
    int cur = n;
    for(int i = 1; i <= m; i++){
        scanf("%lld", &b[i]);
        if(b[i] > mx){
            if(!cnt[cur]){
                --cur;
            }
            if(cur == 0){
                OK = false;
                break;
            }
            --cnt[cur];
            ans += b[i] - a[cur];
        }
        else if(b[i] == mx){
            continue;
        }
        else if(b[i] < mx){
            OK = false;
            break;
        }
    }
    if(OK)printf("%lld", ans);
    else printf("-1");
    return 0;
}