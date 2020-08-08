#include<bits/stdc++.h>
using namespace std;
#define LL long long
int main(){
	LL a,b; cin>>a>>b;
	LL ans = 0;
	ans += a/b;
	a%=b;
	if (a==0) {
		cout<<ans<<endl;
		return 0;
	}
	while (b>a){
		ans += b/a;
		b %= a;
		if (b==0) break;
		swap(a,b);
	}
	printf("%I64d\n",ans);
	return 0;
}