#include<cstdio>
#include <bitset>
#include<string>
#include<stack>
using namespace std;



int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	int left=1;
	int right=n;
	for(int i=0;left<=right;i++){
		printf("%d ",k > 1 ? (k -- % 2 == 0 ? right -- : left ++) : left ++);
	}
	return 0;
 } 