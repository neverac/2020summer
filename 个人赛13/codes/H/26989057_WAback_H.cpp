#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48,ch=getchar();}
	return x*f;
}
const int maxn = 510;
const int mod=998244353;
ll a[maxn][maxn];
ll r[maxn],c[maxn];
int main(){
	ll n=read(),m=read(),k=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			a[i][j]=read()%mod;
	for(int i=1;i<=k;i++){
		char op;
		int x;ll t;
		scanf("%c",&op);
		x=read(),t=read();
		if(op=='r') r[x]=max(r[x],t);
		if(op=='c') c[x]=max(c[x],t);
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			ll t=max(r[i],c[j])%mod;
			//printf("%d %d %lld %lld\n",i,j,a[i][j],t);
			ans=(ans+t*a[i][j]%mod)%mod;
		}
	}
	printf("%lld\n",ans);
	return 0;
}	
/*
3 4 1
1 2 3 4
5 6 7 8
9 10 11 12
r 1 1000000000000000000

*/