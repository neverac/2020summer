#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1; char ch=getchar();
	while (ch<'0' || ch>'9') {if (ch=='-') f=-1; ch=getchar();}
	while (ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
	return x*f;
}
int main(){
	int T=read();
	while (T--){
		int N=read(),K=read();
		if (K<N){
			printf("%d\n",K);
			continue;
		}
		int p = K%(N-1);
		int q = K/(N-1)*N;
		if (!p) printf("%d\n",p+q-1);
		else printf("%d\n",p+q);
//		printf("%d\n",p+1LL*q*N);
	} 
	return 0;
} 