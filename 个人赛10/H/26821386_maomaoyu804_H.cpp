#include <bits/stdc++.h>
using namespace std;

int num[400];
int sum[400];

int main(){
	int n;scanf("%d",&n);
	//int sum=0;
	for(int i=1;i<=n;i++) scanf("%d",&num[i]),sum[i]=sum[i-1]+num[i];
	int ans=9000000;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i<=j){
				int temp=sum[j]-sum[i-1];
				ans=min(ans,abs(sum[n]-temp*2));
			}
			else{
				int temp=sum[n]-sum[i-1]+sum[j];
				ans=min(ans,abs(sum[n]-temp*2));
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}