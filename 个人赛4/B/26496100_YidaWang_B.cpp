#include<bits/stdc++.h>
using namespace std;
#define LL long long
char s[100010];
const int p5 = 4;
int main(){
	LL n=0;
	scanf("%s",s+1);
	int len = strlen(s+1);
	for (int i=1; i<=len; i++){
		n = n*10+s[i]-'0';
		n %= p5;
	}
	n += p5;
	LL ans = pow(1,n) + pow(2,n) + pow(3,n) + pow(4,n);
	ans %= 5;
	printf("%lld\n",ans);
	return 0;
}