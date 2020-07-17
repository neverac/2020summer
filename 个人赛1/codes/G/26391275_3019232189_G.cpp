#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#define N 100006
#define ll long long
#define dd double
#define esp 1e-10
using namespace std;

ll n,m,b[N],g[N];

int main(){
	ll ans=0;
	ll t1=0,t2=0x7fffffff;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i){
		scanf("%lld",&b[i]);
		t1=max(t1,b[i]);
	}
	for(int i=1;i<=m;++i){
		scanf("%lld",&g[i]);
		t2=min(t2,g[i]);
	}
	if(t1>t2){
		printf("-1\n");
		return 0;
	}
	if(n==1&&t1!=t2){
		printf("-1\n");
		return 0;
	}
	if(m==1&&t1!=t2){
		printf("-1\n");
		return 0;
	}
	sort(b+1,b+1+n);
	sort(g+1,g+1+m);
	if(t1!=t2){
		for(int i=1;i<=m;++i)
			ans+=g[i];
		ans+=b[n];
		ans+=b[n-1]*(m-1);
		for(int i=1;i<n-1;++i)
			ans+=m*b[i];
	}
	else{
		for(int i=1;i<=m;++i)
			ans+=g[i];
		for(int i=1;i<n;++i)
			ans+=m*b[i];
	}
	cout<<ans;
}