#include <cstdio>
const int MAXV=1E5+10;
const int MAXN=110;
const int MAXM=13;
int a[MAXM][MAXN][MAXN];
int star_x[MAXV],star_y[MAXV],star_b[MAXV];
int main() {
	int n,q,c;
	scanf("%d%d%d",&n,&q,&c);
	for(int i=1;i<=n;++i) {
		
			int x,y,b;
			scanf("%d%d%d",&x,&y,&b);
			star_x[i]=x;
			star_y[i]=y;
			star_b[i]=b;
			a[0][x][y]+=b;
	}
	for(int cc=1;cc<=c+1;++cc) {
		for(int i=1;i<=n;++i) {
			star_b[i]=(star_b[i]+1<=c?star_b[i]+1:0);
			a[cc][star_x[i]][star_y[i]]+=star_b[i];
		}
	}
	const int m=100;
	for(int cc=0;cc<=c+1;++cc) {
		for(int i=1;i<=m;++i) {
			for(int j=1;j<=m;++j) {
				a[cc][i][j]+=a[cc][i-1][j]+a[cc][i][j-1]-a[cc][i-1][j-1];
			}
		}
	}
	for(int i=1;i<=q;++i) {
		int t,x1,y1,x2,y2;
		scanf("%d%d%d%d%d",&t,&x1,&y1,&x2,&y2);
		t=t%(c+1);
		printf("%d\n",a[t][x2][y2]-a[t][x1-1][y2]-a[t][x2][y1-1]+a[t][x1-1][y1-1]);
	}
	return 0;
}