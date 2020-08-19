#include <iostream>
#include <cmath>
using namespace std;
long long int getPhi(long long int n){
    long long int ans=n,maxi=sqrt(n);
    for(long long int i=2;i<=maxi;i++){
        if(n%i==0){
            ans-=ans/i;
            while(n%i==0){
                n/=i;
            }
        }
    }
    if(n>1){
        ans-=ans/n;
    }
    return ans;
}
long long int gcd(long long int a,long long int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}
int main(){
    long long int t,a,m,d;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld%lld",&a,&m);
        d=gcd(a,m);
        printf("%lld\n",getPhi(m/d));
    }
    return 0;
}