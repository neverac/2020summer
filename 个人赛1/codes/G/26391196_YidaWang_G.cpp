 #include<bits/stdc++.h>
 using namespace std;
 inline int read(){
    int x=0,f=1; char ch=getchar();
    while(ch<'0' || ch>'9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
 }
 int N,M;
 #define LL long long
 #define MAXN 100010
 LL b[MAXN],g[MAXN];
 bool cmp(int A,int B){
 	return A>B;
 }
 int main(){
	N=read(),M=read();
	LL sumg = 0;
	for (int i=1; i<=N; i++) b[i]=read();
	for (int i=1; i<=M; i++) g[i]=read(), sumg += g[i];
	sort(b+1,b+N+1,cmp);
	sort(g+1,g+M+1);
	LL ans = 0;
	if (g[1] < b[1]) {
		puts("-1");
		return 0;
	}
	if (g[1] == b[1]) {
		ans = sumg;
		for (int i=2; i<=N; i++) ans += 1LL*b[i]*M;
		printf("%lld\n",ans);
		return 0;
	}	
	ans = sumg;
	for (int i=2; i<=N; i++) ans += 1LL*b[i]*M;
	ans -= g[1];
	ans += b[1];
	ans += g[1]-b[2];
	printf("%lld\n",ans);
 	return 0;
 }
 
 
 /*
3 2
1 2 1
3 4

2 2
0 1
1 0

2 3
1 0
1 1 2
 */