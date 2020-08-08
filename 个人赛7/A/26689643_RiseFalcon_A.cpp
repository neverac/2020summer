#include<cstdio>
#include<queue>
#include <cstring>
const int ud[4]={0,1,0,-1};
const int lr[4]={1,0,-1,0};
const int MAXN=1E6+10;
struct node {
	int x,y;
	node(int a=0,int b=0) {
		x=a;y=b;
	}
};
int v[MAXN];
char str[MAXN];
int main() {
	int k;
	scanf("%d",&k);
	scanf("%s",str+1);
	int n=strlen(str+1);
	long long ans=0;
	for(int c='a';c<='z';++c) {
		int tail=0,cnt=0,last=0;
		for(int i=1;i<=n;++i) {
			if(str[i]==c) {
				++cnt;
				last=i-1;
			}
			v[i]=cnt;
			while(v[i]-v[tail]>k) {
				++tail;
			}
			if(cnt>=1) {			
				ans+=(i-tail)-(i-last)+1;
				//printf("%c %d %d\n",char(c),i,tail);
			}
		}
		
	}
	printf("%lld\n",ans);
	return 0;
} 