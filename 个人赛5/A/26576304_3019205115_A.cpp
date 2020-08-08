#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long pre[]={1,1,2,9,262144};
long long fai(long long n)
{
    long long res=n,m=n;
    for(int i=2;i*i<=n;i++){
        if(m%i==0){
            res-=res/i;
            while(m%i==0)
                m/=i;
        }
    }
    if(m>1)
        res-=res/m;
    return res;
}
long long Cauchy(long long a,long long b,long long mod){
    long long res=1;
    while(b){
        if(b&1)
            res=res*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return res;
}
long long solve(long long n,long long mod){
    if(mod==1)
        return 0;
    if(n<=4)
        return pre[n]%mod;
    long long Fai=fai(mod);
    long long Next=solve(n-1,Fai);
    return Cauchy(n,Next+Fai,mod);
}
int main(){
    long long n,m;
    cin >>n >>m;
    cout<<solve(n,m)<<endl;
    return 0;
}
