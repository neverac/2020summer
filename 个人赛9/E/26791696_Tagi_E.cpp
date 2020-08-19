#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#define LL long long
using namespace std;


LL gcd(LL a,LL b){
    LL t;
    while(b!=0){
        t=b;
        b=a%b;
        a=t;
    }
    return a;
}

int main()
{
	int t;
	scanf("%d",&t);
	LL a,m;
	while(t--){
		scanf("%lld%lld",&a,&m);
		
		
		LL t=gcd(a,m);
		LL q=m/t,k=a/t;
		LL i=2;
		LL ans=q;
			for(i=2;i<=sqrt(q);i++){
				if(q%i==0){
					ans=ans/i*(i-1);
                	while(q%i==0)q/=i;
				}
			}
			if(q>1)ans=ans/q*(q-1);
             printf("%lld\n",ans);
			
		
//		for(LL i=1;i<q;i++){
//			LL tt=k+i;
//			if(tt<q){
//				LL aa=q%tt;
//				if(tt%aa!=0)ans++;
//			}
//			else if(tt>q){
//				LL aa=tt%q;
//				if(q%tt!=0)ans++;
//			}
//			
//		}
//		printf("%lld\n",ans);
	}
	return 0;
}