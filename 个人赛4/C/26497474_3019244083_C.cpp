#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
char s1[maxn];
int balance[maxn];
int T,n;
int main()
{
	cin>>T;
	while(T--) 
	{
		memset(balance, 0, sizeof(balance));
		int n, x, cnt = 0;
		n = read();
		x = read();
		if(!x) cnt = 1;
		scanf("%s", s1);
		for(int i = 0; i < n; ++i) 
			if(s1[i] == '1') balance[i+1] = balance[i] - 1;
			else balance[i+1] = balance[i] + 1; 
		
		if(balance[n] == 0){
			int i;
			for (i = 1; i <= n; ++i) if (balance[i] == x) {printf("-1\n");break;}
			if(i>n) printf("0\n");
			continue;
		}
		for(int i = 1; i <= n; ++i) if((x - balance[i])/balance[n] >= 0 && (x - balance[i]) % balance[n] == 0) ++cnt;
		printf("%d\n", cnt);
	}
	return 0;
}