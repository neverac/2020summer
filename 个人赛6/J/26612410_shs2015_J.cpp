#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
const int SIZEN = 100010;
int N,K;
int w[SIZEN] = {0};
int main(){
    int ans = 0;
    scanf("%d%d",&N,&K);
    for(int i = 1;i <= N;i++){
        scanf("%d",&w[i]);
    }
    for(int i = 1;i <= N;i++){
        int need = w[i]/(K);
        if(w[i] % (K))need++;
        if(need % 2 == 0)ans += need/2;
        else {
            ans += need/2 + 1;
            w[i+1] = max(w[i+1]-K,0);
        }
    }
    printf("%d\n",ans);
    return 0;
}
