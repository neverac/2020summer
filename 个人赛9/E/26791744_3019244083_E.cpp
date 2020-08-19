#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read()
{
    ll x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll gcd(ll a,ll b)
{
	ll x=a%b;
	while(x>0)
	{ 
        a=b;
        b=x;
        x=a%b;
	}
	return b;
}
int main()
{
	ll T = read();
	while(T--){
		ll a = read();
		ll m = read();
		ll k = gcd(a,m);
		ll p = m/k;
		ll ans = p;
		for(ll i = 2; i*i <= p; ++i)
			if(p % i ==0){
				ans -= ans/i;
				while(p%i==0) p /= i;
			}
		if(p > 1) ans -= ans/p;	
		cout<<ans<<endl;
	}

	return 0;
} 