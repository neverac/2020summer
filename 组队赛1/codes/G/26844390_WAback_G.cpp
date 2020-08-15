#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100010;
const int INF = 100000;
int N,a[MAXN];
int tree[MAXN],f[MAXN],g[MAXN],sf[MAXN],sg[MAXN];
int lowbit(int x) {return x&-x;}
void add(int x){
	for (int i=x; i>=1; i-=lowbit(i)) tree[i]+=1; 
}
int query(int x){
	int re = 0; 
	for (int i=x; i<=INF; i+=lowbit(i)) re+=tree[i]; 
	return re;
}
int main(){
	scanf("%d",&N);
	int mx = 0;
	for (int i=1; i<=N; i++) scanf("%d",&a[i]),mx =max(mx,a[i]);
	for (int i=1; i<=N; i++){
		f[i] = query(a[i]+1);
		add(a[i]);
	}
	for (int i=1; i<=INF; i++) tree[i] = 0;
	for (int i=N; i>=1; i--){
		g[i] = query(a[i]+1);
		add(a[i]);
	}
	long long ans = 0;
	for (int i=1; i<=N; i++){
		ans = ans + min(f[i],g[i]);
	}
	printf("%lld\n",ans);
	return 0;
}

/*
7
3 1 4 1 5 9 2
9
10 4 6 3 15 9 1 1 12
8
9 9 8 8 7 7 6 6
6
8 7 2 5 4 6
*/