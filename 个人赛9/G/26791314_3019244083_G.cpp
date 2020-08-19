#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c[200010],a[200010];
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
	set<int> q[10];
	set<int>::iterator iter;
	ll n = read();
	for(int i=1;i<=n;++i) c[i] = read();
	for(int i=1;i<=n;++i)
	{
		ll x = read();
		q[x].insert(c[i]);
	}
	for(int i=1;i<=n;++i)
	{
		ll x = read();
		q[x].insert(c[i]);
	}
	ll p = read();
	int cnt=0;
	for(int i=1;i<=p;++i)
	{
		ll x = read();
		if(q[x].size() == 0) a[++cnt] = -1;
		else
		{
			iter = q[x].begin();
			int temp = *iter;
			a[++cnt]=temp;
			for(int j=1;j<=3;++j) if(q[j].find(temp)!=q[j].end()) q[j].erase(temp);
		}
	}
	printf("%lld",a[1]);
	for(int i=2;i <= cnt;++i) printf(" %lld",a[i]);
	return 0;
} 