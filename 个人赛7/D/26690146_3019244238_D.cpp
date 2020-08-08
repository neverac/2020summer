#include <stdio.h>
#include <cmath>
using namespace std;

long long ans[10050];
int A[10050][4];

int main()
{
	long long a,tmp;
	int N,num_3,num_5,num_7;
	scanf("%d",&N);
	for(int i=0;i<N;++i)
	{
		scanf("%lld",&a);
		while(a%3==0)
		{
			++A[i][0];
			a/=3;
		}
		while(a%5==0)
		{
			++A[i][1];
			a/=5;
		}
		while(a%7==0)
		{
			++A[i][2];
			a/=7;
		}
	}
	for(int i=0;i<N;++i)
	{
		ans[i]=0;
		num_3=A[i][0],num_5=A[i][1],num_7=A[i][2];
		for(int j=0;j<=num_3;++j)
			for(int jj=0;jj<=num_5;++jj)
				for(int jjj=0;jjj<=num_7;++jjj)
					ans[i]+=(long long)pow(3,j)*pow(5,jj)*pow(7,jjj);
	}
	for(int i=0;i<N;++i)
		printf("%lld\n",ans[i]);
return 0;
}