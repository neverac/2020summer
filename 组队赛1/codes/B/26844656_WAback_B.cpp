#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
const int SIZEN = 5010;
const int hash_mod = 23333333;
int loc[hash_mod + 10];
int f[SIZEN][SIZEN] = {0};
int N;
int a[SIZEN];
int main(){
    scanf("%d",&N);
    for(int i = 1;i <= N;i++)scanf("%d",&a[i]);
    sort(a+1,a+1+N);
    for(int i = 1;i <= N;i++)loc[a[i] % hash_mod] = i;
    int ans = (N == 1?1: 2);
    for(int i = 2;i <= N;i++){
        for(int j = 1;j < i;j++){
            f[i][j] = 2;
            int tmp = 2 * a[j] - a[i];
            if(tmp < 0)continue;
            tmp = (tmp % hash_mod + hash_mod) % hash_mod;
            if(!loc[tmp])continue;
            f[i][j] = max(2,f[j][loc[tmp]] + 1);
            ans = max(ans,f[i][j]);
        }
    }
    printf("%d\n",ans);
    return 0;
}