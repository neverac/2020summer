#include <cstdio>
const int MAXN=2E5+10;
int f[MAXN],s[MAXN];
int find(int x) {
	return x ==f[x] ? x:(f[x]=find(f[x]));
}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i) {
		f[i]=i;
		s[i]=1;
	}
	int cnt=0;
	for(int i=1;i<=m;++i) {
		int x,y;
		scanf("%d%d",&x,&y);
		x=find(x);
		y=find(y);
		if(x!=y) {
			f[x]=y;
			s[y]+=s[x];
			++cnt; 
		}
	}
	
	printf("%d",m-cnt);
	return 0;
} 