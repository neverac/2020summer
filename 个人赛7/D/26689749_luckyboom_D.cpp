#include <bits/stdc++.h>
using namespace std;
int const maxn=50;
long long  a,ans,b;
int yin[10];
void work(int x){
	while(a%x==0){
		yin[x]++;
		a/=x;
	}
}
long long  work2(int x){
	long long u=1,sum=1;
	for(int i=1;i<=yin[x];i++){
		u*=x;
		sum+=u;
		// ans+=u+b/u;
		// printf("%lld %lld\n",u,b/u);
	}
	return  sum;
}
int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		scanf("%lld",&a);
		b=a;
		ans=0;
		memset(yin,0,sizeof(yin));
		long long u3,u5,u7;
		work(3);work(5);work(7);
		u3=work2(3);u5=work2(5);u7=work2(7);
		ans=u3*u5*u7;
		printf("%lld\n",ans);
	}
	return 0;
}