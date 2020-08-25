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
int main()
{
	ll T = read();
	while(T--){
		ll n = read(),m = read(),x = read(),y = read();
		ll ans;
		if(y >= x) ans = m;
		else ans = min(m, (n + (m-1)*y) / x);
		cout<<ans<<endl;
	}
	return 0;
} 