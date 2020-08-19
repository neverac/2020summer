#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200020];
inline ll read()
{
    ll x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int main(){
	int n;
	scanf("%d",&n);
	int cnt = 2*n;
	for(int i = 1;i <= cnt; ++i) a[i] = read();
	sort(a+1,a+cnt+1);
	ll ans = (a[n] - a[1]) * (a[cnt] - a[n+1]);
	ll len = a[cnt] - a[1];
	for(int i = 1; i <= n; ++i) ans = min(ans, len*(a[n+i]-a[i+1]));
	cout<<ans<<endl;
	return 0;
}