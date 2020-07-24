#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k,n,s,p, min=0;
    scanf("%d%d%d%d", &k, &n, &s, &p);
    while(min*s <n){
        min++;
    }
    int sheets=min*k;
    int ans=0;
    while(ans*p < sheets){
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}