#include <cstdio>
using namespace std;
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	printf("1");
	int t = 1;
	for(int i = 2; i <= k; ++i) 
	  if(i%2) printf(" %d",t);
	  else {printf(" %d",n-t+1);++t;}
	if(k%2){
		for(int i = t+1; i <= n-t+1; ++i) printf(" %d",i);
	}
	else for(int i = n-t+1; i >= t; --i) printf(" %d",i);
	return 0;
}