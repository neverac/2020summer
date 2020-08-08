#include <bits/stdc++.h>
using namespace std;
long long a[20];
long long ans=0;
int m;
long long n;
long long gcd(long long a,long long b)
{
    return b==0?a:gcd(b,a%b);
}
long long lcm(long long a, long long b)
{
    return a/gcd(a,b)*b;
}
void dfs(int now,int t,long long v){
	if (now>m) return;
	if (t&1) ans+=n/v;
	else ans-=n/v;
	for (int i=now+1;i<=m;i++){
		long long tmp=lcm(v,a[i]);
		if (tmp>n) continue;
		dfs(i,t+1,tmp);
	}
}
int main(){
	cin>>n>>m;
	for (int i=1;i<=m;i++) cin>>a[i];
	for (int i=1;i<=m;i++){
		if (a[i]<=n)
			dfs(i,1,a[i]);
	}
	cout<<ans<<endl;
	return 0;
}

