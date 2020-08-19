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
#define N 200006
using namespace std;

int n;
ll a[N];

int main(){
    ll ans;
    scanf("%d",&n);
    for(int i=1,j=n*2;i<=j;++i)
        scanf("%lld",&a[i]);
    sort(a+1,a+1+2*n);
    ans=(a[n]-a[1])*(a[n*2]-a[n+1]);
    for(int i=2;i<=n;++i)
        ans=min(ans,(a[i+n-1]-a[i])*(a[n*2]-a[1]));
    cout<<ans;
    //while(1);
}
