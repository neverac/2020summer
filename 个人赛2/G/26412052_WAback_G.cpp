#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

int main(){

	int n,k;
	scanf("%d%d",&n,&k);
	int p=1;
	for(int i=1;i<=k;i++){
		if(i&1) printf("%d ",p);
		else printf("%d ",n-p+1),p++;
	}
	if(k%2==0){
		for(int i=1;i<=n-k;i++)
			printf("%d ",n-k/2-i+1);
	}else{
		for(int i=1;i<=n-k;i++)
			printf("%d ",p+i);
	}
}