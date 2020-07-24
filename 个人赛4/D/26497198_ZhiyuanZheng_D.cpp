#include <bits/stdc++.h>
using namespace std;
int f[20100];
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
int main(){
	int T;
	scanf("%d",&T);
	int xh=1;
	while (xh<=T){
		int n,a,b;
		scanf("%d%d%d",&n,&a,&b);
		int gg=gcd(a,b);
		f[a]=f[b]=1;
		int ss=n/gg-2;
		if(ss%2==0) printf("Case #%d: Iaka\n",xh);
		else printf("Case #%d: Yuwgna\n",xh);
		xh++;
	}
	return 0;
}

