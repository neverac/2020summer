#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std; 
typedef long long LL;
const int MAXN=1E2+10;
int x[MAXN],y[MAXN],z[MAXN][MAXN];
int main() {
	int X,Y,H;
	scanf("%d%d%d",&Y,&X,&H);
	memset(z,63,sizeof z);
	for(int i=0;i<X;++i) {
		scanf("%d",&x[i]);
		for(int j=0;j<Y;++j) {
			z[j][i]=min(z[j][i],x[i]);
		}
	}
	for(int i=0;i<Y;++i) {
		scanf("%d",&y[i]);
		for(int j=0;j<X;++j) {
			z[i][j]=min(z[i][j],y[i]);
		}
	}
	for(int i=0;i<Y;++i) {
		for(int j=0;j<X;++j) {
			int v;scanf("%d",&v);
			z[i][j]=min(z[i][j],z[i][j]*v);
		}
	}
	for(int i=0;i<Y;++i) {
		for(int j=0;j<X;++j) {
			printf("%d ",z[i][j]);
		}printf("\n");
	}
	return 0;
} 