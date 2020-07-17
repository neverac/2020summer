 #include<bits/stdc++.h>
 using namespace std;
 inline int read(){
    int x=0,f=1; char ch=getchar();
    while(ch<'0' || ch>'9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
 }
 int T,N,q[100010],vis[100010],p[100010];
 int main(){
	T=read();
	while (T--){
		N=read();
		for (int i=1; i<=N; i++) q[i]=read();
		for (int i=1; i<=N; i++) vis[i]=0;
		int mx = 0;
		int flag = 0;
		int x = 1;
		for (int i=1; i<=N; i++) {
			if (q[i] != q[i-1]) {
				p[i] = q[i];
				vis[q[i]] = 1;
				mx = max(mx,q[i]);
				continue;
			}
			while (vis[x]) x++;
			p[i] = x;
			mx = max(mx,x);
			vis[x] = 1;
			if (q[i] < mx) flag = 1;
		}
		if (flag){
			puts("-1");
			continue;
		}
		for (int i=1; i<=N; i++) printf("%d ",p[i]); puts("");
	}
 	return 0;
 }
 
 
 /*
4
5
1 3 4 5 5
4
1 1 3 4
2
2 2
1
1
 */