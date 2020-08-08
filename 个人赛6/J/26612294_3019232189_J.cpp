#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <ctime>
#include <vector>
#include <cstdio>
#include <map>
#include <queue>
#define ll long long
#define N 100006
using namespace std;

ll n,k;

int main(){
    ll temp,ans=0;
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;++i){
        scanf("%lld",&temp);
        ans+=(temp-1)/k+1;
    }
    ans=(ans-1)/2+1;
    printf("%lld",ans);

   // while(1);
}
