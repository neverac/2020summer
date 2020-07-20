#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int a[200010],c[18];
int visit[65538];
int main(){
	int A,B,C,S;
	while (scanf("%d",&A)!=EOF){
		if (!A) break;
		scanf("%d%d%d",&B,&C,&S);
		int cnt=0;
		a[++cnt] = S;
		visit[S]=1;
		for (int i=1; ; i++){
			int q = (1LL*A*a[cnt]+B)%C;
			if (!visit[q]) a[++cnt]=q,visit[q]=1;
			else break;
		//	if (q!=a[1] && q!=a[cnt]) a[++cnt]=q;
			//else break;
		}
		//for (int i=1; i<=cnt; i++) printf("%d  ",a[i]); puts("");
		memset(c,0,sizeof(c));
		for (int i=0; i<16; i++) {
			c[i] = (a[1] >> i) &1;
			for (int j=2; j<=cnt; j++) {
				if (((a[j]>>i)&1)!=c[i]){
					c[i]=3;
					break;
				}
			}
		}
		for (int i=16; i; i--){
			if (c[i-1]==3) putchar('?');
			else putchar(c[i-1]+48);
		}
		puts("");
		for (int i=1; i<=cnt; i++) visit[a[i]]=0;
	}
	return 0;
}

/*
2 5 18 3
1 1 64000 0
2 0 16 2
256 85 32768 21845
1 4097 32776 248
0
*/