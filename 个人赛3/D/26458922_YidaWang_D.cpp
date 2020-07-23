#include<bits/stdc++.h>
using namespace std;
char s[200];
#define LL long long
int a[400010],b[400010],cnt1,cnt2,sum[400010];
bool flag[400010];
int prime[400010],cnt;
void getprime(int n){
	flag[1]=1;
	for (int i=2; i<=n; i++){
		if (!flag[i]) prime[++cnt]=i;
		for (int j=1; j<=cnt && i*prime[j]<=n; j++){
			flag[i*prime[j]]=1;
			if (i%prime[j]==0) break;
		}
 	}
}
int main(){
	int n; cin>>n;
	for (int i=1; i<=n; i++) scanf("%d",&a[i]),cnt1+=(a[i]==1),cnt2+=(a[i]==2);
	getprime(2*n);
	int tot=0;
	for (int i=1; i<=n; i++){
		if (!flag[sum[i-1]+1]){
			if (cnt1) cnt1--,b[i]=1,sum[i]=sum[i-1]+1,tot++;
			else cnt2--,b[i]=2,sum[i]=sum[i-1]+2;
		} else {
			if (cnt2) cnt2--,b[i]=2,sum[i]=sum[i-1]+2,tot+=(!flag[sum[i]]);
			else cnt1--,b[i]=1,sum[i]=sum[i-1]+1;
		} 	
	}
	for (int i=1; i<=n; i++) printf("%d ",b[i]);
	return 0;
}