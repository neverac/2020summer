#include<bits/stdc++.h>
using namespace std;

int main(){
    int k, n, s, p;
    cin>>k>>n>>s>>p;
    int o = n / s;
    if(n % s > 0) ++o;
    o *= k;
    int ans = (o / p);
    
    if(o % p > 0) ans++;
    printf("%d\n", ans);

    return 0;
}