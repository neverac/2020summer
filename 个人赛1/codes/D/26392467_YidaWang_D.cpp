 #include<bits/stdc++.h>
 using namespace std;
 inline int read(){
    int x=0,f=1; char ch=getchar();
    while(ch<'0' || ch>'9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
 }
 #define MAXN 200
 int N,M,K;
 int ft[MAXN],lf[MAXN],up[MAXN][MAXN];
 int main(){
	N = read(),M=read(),K=read();
	for (int i=1; i<=M; i++) ft[i]=read();
	for (int i=1; i<=N; i++) lf[i]=read();
	for (int i=1; i<=N; i++)
		for (int j=1; j<=M; j++) up[i][j]=read();
	for (int i=1; i<=N; i++){
		for (int j=1; j<=M; j++){
			if (up[i][j]){
				int cnt=0;
				for (int x = 1; x <= M; x++) if (up[i][x]) cnt++;
				if (cnt==1) {up[i][j] = lf[i]; continue;}
				cnt=0;
				for (int x = 1; x <= N; x++) if (up[x][j]) cnt++;
				if (cnt==1) {up[i][j] = ft[j]; continue;}
				up[i][j] = min(lf[i],ft[j]);
			}
		}	
	}
	for (int i=1; i<=N; i++){
		for (int j=1; j<=M; j++){
			printf("%d ",up[i][j]);
		} puts("");
	}
	return 0;
 }
 
 /*
3 7 3
2 3 0 0 2 0 1
2 1 3
1 0 0 0 1 0 0
0 0 0 0 0 0 1
1 1 0 0 0 0 0
 */
 
 