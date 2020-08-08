#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
int main(){
    long long  n,k,ans=0,a;
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a);
        ans+=a/k;
        if(a%k)ans++;
    }
    if(ans&1)ans=ans/2+1;
    else ans=ans/2;
    printf("%lld\n",ans);
    return 0;
    
}