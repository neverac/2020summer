#include<bits/stdc++.h>
using namespace std;
#define LL long long
int main(){
	LL N,M,X,Y;
	int T; cin>>T;
	while (T--){
		scanf("%lld%lld%lld%lld",&N,&M,&X,&Y);
		if (X <= Y) {
			cout<<M<<endl;
		} else {
			cout<<min(M, (LL)(N+(M-1)*Y)/X)<<endl;	
		}
	}
	return 0;
}