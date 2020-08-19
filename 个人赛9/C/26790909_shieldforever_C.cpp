#include<bits/stdc++.h>
using namespace std;
#define N 2020
typedef long long LL;
LL x[N], y[N], z[N], used[N];
int n;
void init(){
    cin>>n;
    for(int i = 1; i <= n; i++){
        scanf("%lld%lld%lld", &x[i], &y[i], &z[i]);
    }
    return ;
}
LL getdis(LL x1, LL y1, LL z1, LL x2, LL y2, LL z2){
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2);
}
void solve(){
    for(int i = 1; i <= n; i++){
        if(!used[i]){
            used[i] = 1;
            LL mindis = LONG_LONG_MAX, minid = -1;
            for(int j = i + 1; j <= n; j++){
                if(used[j]) continue;
                LL dis = getdis(x[i], y[i], z[i], x[j], y[j], z[j]);
                if(dis < mindis){
                    mindis = dis; minid = j;
                }
            }
            printf("%d %d\n", i, minid); used[minid] = 1;
        }
    }
    return ;
}
int main(){
    init();
    solve();
    return 0;
}