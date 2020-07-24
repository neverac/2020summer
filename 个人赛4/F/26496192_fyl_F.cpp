#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int k,n,s,p;
	scanf("%d%d%d%d",&k,&n,&s,&p);
	int num=n/s;
	if(n%s) num++;
	num*=k;
	int ans=num/p;
	if(num%p) ans++;
	printf("%d\n",ans);
	return 0;
}