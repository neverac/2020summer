#include<bits/stdc++.h>
using namespace std;
long long k,n,s,p;
int main(){
	cin>>k>>n>>s>>p;
	long long u,v;
	if(s>=n){
		u=k/p;
		if(p*u<k)u++;
		printf("%lld\n",u);
	}
	else{
		u=n/s;
		if(u*s<n)u++;
		v=u*k/p;
		if(v*p<u*k)v++;
		printf("%lld\n",v);
	}
	
	return 0;
}