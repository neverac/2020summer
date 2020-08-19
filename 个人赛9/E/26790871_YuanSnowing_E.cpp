#include<bits/stdc++.h>
using namespace std;
long long s[150],k,d;
int T;  
void prime(long long m){
	k=0;
	for(long long i=2;i*i<=m;i++){
		if(m%i==0){
			s[k++]=i;
			while(m%i==0) m/=i;
		}
	}
	if(m>1) s[k++]=m;
}
long long quc(long long m){
	long long p[10020],i,j,t=0,sum=0,z;
	p[t ++]=-1;
	for(i=0;i<k;i++){
		z=t;
		for(j=0;j<z;j++) p[t++] = p[j]*s[i]*(-1);
	}
	for(i=1;i<t;i++) sum+=m/p[i];
	return sum;
}
int main(){
	cin>>T;
	while (T--){
		long long a,m;
		cin>>a>>m;
		d =__gcd(a,m);
		a/=d;
		m/=d;
		prime(m);
		cout<<m-quc(a+m)+quc(a-1)<<endl;
	}
}