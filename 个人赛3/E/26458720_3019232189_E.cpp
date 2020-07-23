#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#define ll long long
#define N 100006
using namespace std;

int n;
ll f[N][2];

int main(){
    ll mx1=0,mx2=0;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%lld",&f[i][0]);
    for(int i=1;i<=n;++i)
        scanf("%lld",&f[i][1]);
    
    for(int i=1;i<=n;++i){
        f[i][0]=max(f[i][0],mx2+f[i][0]);
        f[i][1]=max(f[i][1],mx1+f[i][1]);
        mx1=max(mx1,f[i][0]);
        mx2=max(mx2,f[i][1]);
    };
    printf("%lld\n",max(mx1,mx2));
    
    //while(1);
}
