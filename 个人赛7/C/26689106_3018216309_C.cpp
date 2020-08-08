#include <bits/stdc++.h>
using namespace std;
int a[110],b[110];
int main() {
	int n;
	scanf("%d",&n);
	int ina=1,inb=1;
	for(int i=1;i<=n;i++){
	    scanf("%d",&a[i]);
	    
	}
	for(int i=1;i<=n;i++){
	    scanf("%d",&b[i]);
	    
	}
	while(ina<=n&&inb<=n){
	    while((ina<=n&&inb<=n)&&a[ina]>b[inb])inb++;
	    while((ina<=n&&inb<=n)&&a[ina]<b[inb])ina++;
	}
	if(inb<=n) printf("%d",n-inb+1);
	else printf("%d",n-ina+1);
	
	return 0;
}