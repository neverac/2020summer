#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;
int a[1000010];
int main(){
	int n,k;
	long long sum=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=k;i++){
		sum+=a[i];
	}
	printf("%lld\n",sum);
	
}