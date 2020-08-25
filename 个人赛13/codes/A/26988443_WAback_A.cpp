#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;
#define ll long long
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		ll n,m,x,y;
		scanf("%lld%lld%lld%lld",&n,&m,&x,&y);
		if(y>=x){
			printf("%lld\n",m);
			continue;
		}
		n+=1ll*(m-1)*y;
		ll t=n/x;
		printf("%lld\n",min(t,m));
	}
	return 0;
}	
