#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    return b?gcd(b,a%b):a;
}

int main(){
    int t;scanf("%d",&t);
    for(int i=1;i<=t;i++){
        int n,a,b;scanf("%d%d%d",&n,&a,&b);
        //cout<<n<<a<<b<<endl;
        n/=gcd(a,b);
        //cout<<n<<endl;
        if(n&1) printf("Case #%d: Yuwgna\n",i);
        else printf("Case #%d: Iaka\n",i);
    }
    return 0;
}