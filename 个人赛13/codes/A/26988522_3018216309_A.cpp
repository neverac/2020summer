#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 1e6+10;
ll x,y,n,m;
double minn=0x3f3f3f3f;



int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%lld%lld%lld%lld",&n,&m,&x,&y);
        if (y >= x) printf("%lld\n",m);
        else{
            ll tem =y*(m-1)+n;
            ll ans=min(tem/x,m);
            printf("%lld\n",ans);
        }
    }

}

