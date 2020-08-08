#include <stdio.h>
using namespace std;

int main()
{
	int A[150],B[150];
	int N,p1=0,p2=0;
	scanf("%d",&N);
	for(int i=0;i<N;++i)
		scanf("%d",&A[i]);
	for(int i=0;i<N;++i)
		scanf("%d",&B[i]);
	while(p1!=N && p2!=N)
	{
		if(A[p1]>B[p2])
			++p2;
		else
			++p1;
	}
	printf("%d",2*N-p1-p2);
return 0;
}