#include <bits/stdc++.h>
using namespace std;

int num[200005],a[200005],b[200005];

int main(){
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&num[i]);
	a[1]=1;
	int maxx=0;
	for(int i=2;i<=n;i++){
		if(num[i]>num[i-1]) a[i]=a[i-1]+1;
		else a[i]=1;
		maxx=max(maxx,a[i]);
	}
	b[n]=1;
	for(int i=n-1;i>=1;i--){
		if(num[i]<num[i+1]) b[i]=b[i+1]+1;
		else b[i]=1;
	}
	for(int i=1;i<=n-2;i++){
		if(num[i+2]>num[i]) maxx=max(maxx,a[i]+b[i+2]);
	}
	cout<<maxx<<endl;
	return 0;
}