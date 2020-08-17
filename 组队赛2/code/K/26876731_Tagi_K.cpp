#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;

int a[1005];

int main()
{
	int t;
	int n;
	scanf("%d",&t);
	while(t--){
		memset(a,0,sizeof(a));
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		long long ans=0;
		for(int i=0;i<n-1;i++){
			sort(a,a+n);
			int k=a[i]+a[i+1];
			ans+=k;
			a[i+1]=k;
		}
		printf("%lld\n",ans);
	} 
}