#include<iostream>
#include<cstdio>
using namespace std;
long long gcd(long long a,long long b){
    return b==0?a:gcd(b,a%b);
}
long long getAns(long long n){
    long long ans=n;
    for(long long i=2;i*i<=n;i++){
        if(n%i==0){
            ans-=ans/i;
            while(n%i==0)n/=i;
        }
    }
    if(n>1)ans-=ans/n;
    return ans;
}
int main(){
    int t;
    long long a,m,temp;
    cin >> t;
    while(t--){
        cin >> a >> m;
        temp=m/gcd(a,m);
        cout << getAns(temp) << endl;
    }
}