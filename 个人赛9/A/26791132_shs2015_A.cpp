#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
const int SIZEN = 200010;
int a[SIZEN] = {0};
int N;
int main(){
    scanf("%d",&N);
    for(int i = 1;i <= 2*N;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+2*N);
    LL ans = 1LL*(a[N] - a[1])*(a[2*N]-a[N+1]);
    for(int i = 2;i <= N;i++){
        ans = min(ans,1LL*(a[i+N-1]-a[i]) * (a[2*N] - a[1]));
    }
    printf("%lld\n",ans);
    return 0;
}