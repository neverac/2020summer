#include <stdio.h>
#include <string.h>
#include <cmath>
using namespace std;

char n[100050];

int main()
{
	scanf("%s",n);
	int len=strlen(n),ans=1,N=0;
	if(len>1)
		N+=(n[len-2]-'0')*10;
	N+=n[len-1]-'0';
	switch(N%4)
	{
		case 0:{
			ans+=1+1;
			break;
		}
		case 1:{
			ans+=2+3;
			break;
		}
		case 2:{
			ans+=4+4;
			break;
		}
		case 3:{
			ans+=3+2;
			break;
		}
	}
	if((n[len-1]-'0')&1)	ans+=4;
	else					ans+=1;
	printf("%d\n",ans%5);
return 0;
}