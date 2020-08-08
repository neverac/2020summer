#include<bits/stdc++.h>
using namespace std;

const int maxn=2e5+7;
int a[maxn],n,zuo[maxn],you[maxn];
int main(){
	scanf("%d",&n);
	zuo[0]=0;
	a[0]=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>a[i-1]){
			zuo[i]=zuo[i-1]+1;
			if(ans<zuo[i])ans=zuo[i];
		}
		else zuo[i]=1;
	}
	a[n+1]=1e9+7;
	you[n+1]=0;
	for(int i=n;i>=1;i--){
		if(a[i]<a[i+1]){
			you[i]=you[i+1]+1; 
		}
		else you[i]=1;
	}
	for(int i=2;i<n;i++){
		if(a[i-1]<a[i+1]){
			ans=max(ans,zuo[i-1]+you[i+1]);
		}
	}
	cout<<ans<<endl;
}