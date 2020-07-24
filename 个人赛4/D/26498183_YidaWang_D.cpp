#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
	if (!b) return a; return gcd(b,a%b);
}
int main(){
	int t; scanf("%d",&t);
	int cnt=0;
	while (t--){
		cnt++;
		int n,a,b; scanf("%d%d%d",&n,&a,&b);
		int d = gcd(a,b);
		printf("Case #%d: ",cnt);
		if (n/d%2==1){
			puts("Yuwgna");
		} else {
			puts("Iaka");
		}
	}
	return 0;
}