#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
void work(){
    LL n,m,x,y;
    scanf("%lld%lld%lld%lld",&n,&m,&x,&y);
    if(y >= x){
        printf("%lld\n",m);
    }
    else{
        printf("%lld\n",min((n + (m - 1) * y )/ x,m));
    }
}
int main(){
    int T;scanf("%d",&T);
    while(T--)work();
    return 0;
}