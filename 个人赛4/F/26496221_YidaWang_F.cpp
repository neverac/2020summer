#include<bits/stdc++.h>
using namespace std;
int k,n,s,p;
int main(){
	scanf("%d%d%d%d",&k,&n,&s,&p);
	int a = ceil(1.0*n/s);
	int b = k*a;
//	printf("%d %d \n",a,b);
	int c = ceil(1.0*b/p);
	printf("%d\n",c);
	return 0;
}