#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<bitset>
#include<set>
using namespace std;


int main()
{
	int t;
	scanf("%d",&t);
	int k,l;
	while(t--){
		scanf("%d%d",&k,&l);
		if(l>=2000){
			printf("-1\n");
			continue;
		}
		int res=(1999+k)/1998;
		int mo=(1999+k)%1998;
		long long ans=k+2;
		printf("1999\n");
		printf("-1 ");
		for(int i=1;i<1998;i++){
			printf("%d ",res);
		}
		printf("%lld\n",res+mo);
	}
	return 0;
}