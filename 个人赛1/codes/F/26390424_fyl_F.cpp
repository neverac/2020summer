#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;
int a[100010],num[100010];
int main(){
	ll sum=0;
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		num[a[i]]++;
		sum+=a[i];
	}
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		int b,c;
		scanf("%d%d",&b,&c);
		sum+=(c-b)*num[b];
		num[c]+=num[b];
		num[b]=0;
		printf("%lld\n",sum);
	}
}	
/*
4
1 2 3 4
3
1 2
3 4
2 4
*/