#include <iostream>
#include <cmath>
using namespace std;
long long int sol(){
    long long int n,ans=-1,n2,z;
    scanf("%lld",&n);
    n2=n*n;
    for(long long int i=1;i<=n;i++){
        if(n2%i==0){
            z=i;
            ans=max(ans,(n+n2/z)^(n+z));
            z=n2/i;
            ans=max(ans,(n+n2/z)^(n+z));
        }
    }
    return ans;
}
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        printf("%lld\n",sol());
    }
    return 0;
}