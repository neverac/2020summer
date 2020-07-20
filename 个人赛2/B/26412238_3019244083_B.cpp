#include <cstdio>
#include <cstring>
using namespace std;
unsigned int a[65537];
unsigned int vis[65537];
int main(void)
{
	unsigned int A,B,C,S,cnt = 0,x,k;
	while(1)
	{
		scanf("%d",&A);
		if(A == 0) break;
		memset(vis , 0, sizeof(vis));
		scanf("%d%d%d",&B,&C,&S);
		cnt = 0;
		while(vis[S] == 0)
		{
			vis[S] = 1;
			a[cnt++] = S;
			S=(A*S+B) % C;
		}
		x=1<<15; //max
	//	cout<<cnt<<endl;
	//	for(int i = 1; i <= cnt; ++i) cout<<a[i]<<endl;
		for(int i = 1 ; i <= 16; ++i)
		{
			k=a[0] & x;
			int j;
			for(j = 1; j < cnt; ++j) if(k != (a[j]&x)) break;
			if(j != cnt) printf("?");
			else if(k == 0) printf("0");
			else printf("1");
			x /= 2;
		}
		printf("\n");
	}
	return 0;
}