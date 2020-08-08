#include <cstdio>
#include <iostream>
using namespace std;
int main(){
	int t;
    long long n,k;
    long long ans;
	scanf("%d",&t);
	while(t--){
        scanf("%lld%lld",&n,&k);
		if(n>k) {
            printf("%lld\n",k);
        }
		else{
            ans = k+k/(n-1);
			if(k%(n-1)==0){
                ans--;
            }
			printf("%lld\n",ans);
		}
	}
}