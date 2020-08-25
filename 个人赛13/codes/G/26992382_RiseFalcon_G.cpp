#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
const int MAXN=1E7+10;
const LL mod=998244353;
LL input() {
	LL x;scanf("%lld",&x);
	return x;
}
struct pairs{
	LL iai,ai,id;
	pairs(LL _ai,LL _iai,LL _id) {
		ai=_ai;
		iai=_iai;
		id=_id;
	}
}; 
LL n,p,x,y,z,b1;
LL fin[MAXN],b[MAXN];
LL next(LL i) {
	return (x*fin[i]+y*b[i]+z)%p;
}
stack<pairs>q;
int main() {
	n=input();p=input();
	x=input();y=input();z=input();
	b[1]=input();
	LL ans=fin[1]=b[1]%mod;
	
	LL sum=b[1];
	q.push(pairs(b[1],1*b[1],1));
	for(LL i=2;i<=n;++i) {
		b[i]=next(i-1);
		while(!q.empty()&&q.top().ai>=b[i]) {
			pairs o=q.top();
			sum+=mod-o.iai;
			sum%=mod;
			q.pop();
		}
		if(!q.empty()) {
			pairs o=q.top();
			q.push(pairs(b[i],b[i]*(i-o.id)%mod,i));
			sum+=b[i]*(i-o.id)%mod;
			sum%=mod;
		}else {
			q.push(pairs(b[i],b[i]*i%mod,i));
			sum+=b[i]*i;
		}
		ans+=sum;
		ans%=mod;
		fin[i]=ans;
	//	printf("[%d] b:=%lld fin:=%lld sum:=%lld \n",i,b[i],fin[i],sum);
	}
	ans=0;
	for(LL i=1;i<=n;++i) {
		ans^=fin[i];
	}printf("%lld\n",ans);
	return 0;
} 