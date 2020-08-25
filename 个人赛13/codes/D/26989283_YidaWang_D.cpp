#include<bits/stdc++.h>
using namespace std;
#define LL long long
int N,M;
#define Pa pair<int,int>
#define MP make_pair
Pa e[200010];
int f[200010],d[200010]; 
int find(int x){
	if (x==f[x]) return x; return f[x]=find(f[x]);
}
int main(){
	scanf("%d%d",&N,&M);
	for (int i=1; i<=M; i++){
		int x,y; scanf("%d%d",&x,&y);
		if (x < y) swap(x,y);
		e[i]=MP(x,y);
	}
	for (int i=1; i<=N; i++) f[i] = i;
	sort(e+1,e+M+1);
	int num = 0;
	for (int i=1; i<=M; i++){
		int u = e[i].first, v = e[i].second;
		int fu = find(u), fv = find(v);
		if(fu == fv) continue;
		f[fu] = fv;
		num++;
		d[u]++, d[v]++;
		if (num == N-1) break;
	}
	int D = 0;
	for (int i=1; i<=N; i++) D = max(D,d[i]);
	printf("%d\n",D);
	return 0;
}