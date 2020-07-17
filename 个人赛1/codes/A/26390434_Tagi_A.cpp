#include<cstdio>
#include<algorithm>
using namespace std;

//bool cmp(int a,int b){
//	return  a<=b;
//}

int main()
{
	int k,n;
	scanf("%d%d",&n,&k);
	int *p=new int[n] ;
	for(int i=0;i<n;i++){
		scanf("%d",&p[i]);
	}
	sort(p,p+n);
	int sum(0);
//	for(int i=0;i<n;i++){
//		printf("%d ",p[i]);
//	}
//	printf("\n");
	for(int i=0;i<k;i++){
		sum+=p[i];
	}
	printf("%d",sum);
	delete []p;
	return 0;
}