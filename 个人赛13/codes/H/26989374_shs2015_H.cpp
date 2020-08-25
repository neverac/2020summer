#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
const int SIZEN = 510;
const LL mod = 998244353;
int N,M,K;
LL a[SIZEN][SIZEN];
LL b[SIZEN][SIZEN];
LL lastn[SIZEN];
LL lastm[SIZEN];
int main(){
    scanf("%d%d%d",&N,&M,&K);
    for(int i = 1;i <= N;i++){
        for(int j = 1;j <= M;j++)scanf("%lld",&a[i][j]),a[i][j] %= mod;
    }
    for(int i = 1;i <= K;i++){
        char opt[10];
        int x;LL y;
        scanf("%s%d%lld",opt+1,&x,&y);
        if(opt[1] == 'r')lastn[x] = max(lastn[x],y);
        else lastm[x] = max(lastm[x],y);
    }
    LL ans = 0;
    for(int i = 1;i <= N;i++){
        for(int j = 1;j <= M;j++){
            ans = (ans + max(lastn[i],lastm[j]) % mod * a[i][j] % mod) % mod;
        }
    }
    printf("%lld\n",(ans + mod)%mod);
    return 0;
}