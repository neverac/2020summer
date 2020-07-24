#include <bits/stdc++.h>
using namespace std;
int T,a,n,b,k,tmp;
int main(){
    cin >> T;
    for(int tt = 1;tt <= T; ++ tt){
    	cin >> n >> a >> b;
    	k = __gcd(a,b);
    	bool f = 0;
    	tmp = k;
    	while(tmp <= n){
    		if(tmp != a && tmp != b) f = !f;
    		tmp += k;
    	}
    	if(!f) printf("Case #%d: Iaka\n",tt);
    	else printf("Case #%d: Yuwgna\n",tt);
    }
    return 0;
}