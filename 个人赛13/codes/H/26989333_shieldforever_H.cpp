#include<bits/stdc++.h>
using namespace std;
#define N 550
typedef long long LL;
const LL P = 998244353;
LL a[N][N], n, m, k;
LL row[N], col[N];
int main(){
    cin>>n>>m>>k;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%lld", &a[i][j]);
            a[i][j] %= P;
        }
    }
    for(int i = 1; i <= k; i++){
        char c; LL num, t; cin>>c>>num>>t;
        if(c == 'c') col[num] = t;
        else row[num] = t;
    }
    LL ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            LL t = max(row[i], col[j]) % P;
            ans = (ans + t * a[i][j] % P) % P;
        }
    }
    cout<<ans<<endl;
    return 0;
}