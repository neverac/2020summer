#include<iostream>
using namespace std;
long long int exponial[5]={1,1,2,9,262144};
long long int phi(long long int n){
    long long int res=n,m=n;
    for(int i=2;i*i<=n;i++){
        if(m%i==0){
            res-=res/i;
            while(m%i==0){
                m/=i;
            }
        }
    }
    if(m>1){
        res-=res/m;
    }
    return res;
}
long long int powM(long long int a,long long int b,long long int mod){
    long long int res=1;
    while(b){
        if(b&1){
            res=res*a%mod;
        }
        b>>=1;
        a=a*a%mod;
    }
    return res;
}
long long int solve(long long int n,long long int mod){
    if(mod==1){
        return 0;
    }
    if(n<=4){
        return exponial[n]%mod;
    }
    long long int PHI=phi(mod);
    long long int Next=solve(n-1,PHI);
    return powM(n,Next+PHI,mod);
}

int main(){
    //freopen("in.txt","r",stdin);
    long long int n,m;
    scanf("%lld%lld",&n,&m);
    printf("%lld\n",solve(n,m));
    return 0;
}