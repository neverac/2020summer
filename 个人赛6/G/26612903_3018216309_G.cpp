#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
   ll a,b;
   scanf("%lld%lld",&a,&b);
   ll t;
   ll ans = 0;
   while(b){
       ans += a/b;
       a %= b;
       t=a;
       a=b;
       b=t;
    }
   printf("%lld",ans);
}
