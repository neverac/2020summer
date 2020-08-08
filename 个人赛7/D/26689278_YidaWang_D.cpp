#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL a[20200],N,ans;
int main(){
	scanf("%d",&N);
	for (int i=1; i<=N; i++) scanf("%lld",&a[i]);
	for (int i=1; i<=N; i++){
		LL x = a[i];
		ans = 1;
		while (x%2==0){
			x/=2;
		}
		LL p = 1,tmp = 1;
		while (x%3==0){	
			x/=3;
			p*=3;
			tmp += p;
//			ans += p;
//			ans += x;
		}
		ans *= tmp;
		p = 1, tmp = 1; 
		while (x%5==0){
			x/=5;
			p*=5;
			tmp += p;
//			ans += x;
		}
		ans *= tmp;
		p = 1, tmp = 1;
		while (x%7==0){
			x/=7;
			p*=7;
			tmp += p;
//			ans += x;
		}
		ans *= tmp;
		printf("%lld\n",ans);
	}
	
	return 0;
}