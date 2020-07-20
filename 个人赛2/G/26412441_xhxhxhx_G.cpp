#include <cstdio>
using namespace std;

int main()
{
	int n, k;

	scanf("%d%d", &n, &k);

	int lb = 2, rb = n, i = 1;
	printf("1 ");
	for(; i < k; ++i)
	{
		printf("%d ", i & 1 ? rb-- : lb++);
	}
	if(i & 1)
	{
		for(; lb < rb; ++lb)
		{
			printf("%d ", lb);
		}
		printf("%d\n", rb);
	}
	else
	{
		for(; lb < rb; --rb)
		{
			printf("%d ", rb);
		}
		printf("%d\n", lb);
	}

	return 0;
}