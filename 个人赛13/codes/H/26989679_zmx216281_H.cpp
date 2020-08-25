#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int mod = 998244353;
long long a[510][510];
long long ti[510][510];
int main(){
    long long n,m,k,x,t;
    long long ans = 0;
    char w;
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            scanf("%lld",&a[i][j]);
            a[i][j]%=mod;
        }
    }
    while(k--){
        cin >> w ;
        scanf("%lld%lld",&x,&t);
        if(w=='r'){
            for(int i=1;i<=m;i++){
                ans+=(((t-ti[x][i])%mod)*a[x][i])%mod;
                ti[x][i] = t;
            }
        }
        else{
            for(int i=1;i<=n;i++){
                ans+=(((t-ti[i][x])%mod)*a[i][x])%mod;
                ti[i][x] = t;
            }
        }
    }
    printf("%lld\n",ans%mod);
}