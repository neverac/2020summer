#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#define N 100006
#define ll long long
#define dd double
#define esp 1e-10
using namespace std;

int n,m;
int num[N];

int main(){
	ll ans=0;
	int t1,t2;
	memset(num,0,sizeof(num));
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&t1);
		ans+=t1;
		++num[t1];
	}
	scanf("%d",&m);
	for(int i=1;i<=m;++i){
		scanf("%d%d",&t1,&t2);
		num[t2]+=num[t1];
		ans+=(t2-t1)*num[t1];
		num[t1]=0;
		printf("%lld\n",ans);
	}
}