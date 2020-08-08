#include <algorithm>
#include <string.h>
#include <string>
#include<math.h>
#include<map>
#include<unordered_map>

using namespace std;

int main()
{
	long long n,k,s;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		if(n>k)
            printf("%lld\n",k);
		else
		{
			s=k+k/(n-1);
			if(k%(n-1)==0)
			s--;
			printf("%lld\n",s);
		}
	}
}
