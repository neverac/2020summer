#include <bits/stdc++.h>
using namespace std;
int n;
int const maxn=1003;
int a[maxn],b[maxn];
int main(){
	scanf("%d",&n);
	// int ma1=-100,wei1,ma2=-1000,wei2;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		// if(a>ma1){
		// 	ma1=a;wei1=i;
		// }
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
		// if(a>ma2){
		// 	ma2=a;wei2=i;
		// }
	}
	// if(ma2>ma1){
	// 	cout<<n-wei2+1<<endl;
	// }
	// else{
	// 	cout<<n-wei1+1<<endl;
	// }
	int tot1=0,tot2=0;
	while(tot1<n&&tot2<n){
		if(b[tot2+1]>a[tot1+1]){
			tot1++;
		}
		else{
			tot2++;
		}
	}
	if(tot1==n)printf("%d\n",n-tot2);
	else printf("%d\n",n-tot1);
	return 0;
}