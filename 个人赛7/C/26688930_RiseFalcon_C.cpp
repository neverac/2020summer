#include<cstdio>
const int MAXN=120;
int a[MAXN],b[MAXN];
int main() {
	int N,M;
	scanf("%d",&N);
	for(int i=1;i<=N;++i) {
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=N;++i) {
		scanf("%d",&b[i]);
	}
	int ia=1,ib=1;
	while(ia<=N&&ib<=N) {
		if(a[ia]<b[ib]) {
			++ia;
		}else {
			++ib;
		}
	}
	//printf(">> %d %d\n",ia,ib);
	printf("%d\n",N-ia+1+N-ib+1);
	return 0;
} 