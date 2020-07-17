#include<bits/stdc++.h>
using namespace std;
long long int sum,a,n,q,b,c;
map<long long int, int> mmp;
int main(){
	scanf("%lld",&n);
	while(n --){
		scanf("%lld",&a);
		sum += a;
		if(!mmp.count(a)) mmp[a] = 1;
		else mmp[a] ++;
	}
	scanf("%lld",&q);
	while(q --){
		scanf("%lld%lld",&b,&c);
		if(mmp.count(b)){
			int tmp = mmp[b];
			sum -= b*tmp;
			sum += c*tmp;
			if(!mmp.count(c)) mmp[c] = 0;
			mmp[c] += tmp;
			mmp[b] = 0;
		}
		printf("%lld\n",sum);
	}
    return 0;
}