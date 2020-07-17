#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;

int rec[100100];

int main()
{
	long long n;
	int i,a,b,top;
	scanf("%lld",&n);
	while(n)
    {
        top++;
		rec[top]=(n-1)%26;
		n--;
		n/=26;
	}
	for(i=top;i>=1;i--)
        printf("%c",'a'+rec[i]);
	printf("\n");
	return 0;
}

