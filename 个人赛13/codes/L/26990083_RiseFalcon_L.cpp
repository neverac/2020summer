#include <bits/stdc++.h>
using namespace std;
const int MAXN=1000;
struct vec {
	int a[10],tail0,tail1;
	vec() {memset(a,0,sizeof a);tail0=0,tail1=0;}
	int& operator[](const int&i) {
		return a[i];
	}
	const int& operator[](const int&i) const{
		return a[i];
	} 
	void clear() {
		memset(a,0,sizeof a);
	}
	void show() {
		for(int i=9;i>=0;--i) {
			for(int c=0;c<a[i];++c) {
				printf("%d",i);
			}
		}
		if(tail1!=-1)printf("%d",tail1);
		printf("%d",tail0);
		printf("\n");
	}
}temp[MAXN];
bool operator < (const vec&a,const vec&b) {
	for(int i=9;i>=0;--i) {
		if(a[i]!=b[i]) {
			return a[i]<b[i];
		}
	}
	if(a.tail1!=b.tail1) return a.tail1<b.tail1;
	return a.tail0<b.tail0;
}
int doing() {
	int tail=0;
	vec w;
	for(int i=0;i<=9;++i) {
		scanf("%d",&w[i]);
	}
	{
		int sum=0;
		for(int i=0;i<=9;++i) {
			sum+=w[i];
		}
		if(sum==w[0]) {
			printf("0\n");
			return 0;
		}
	}
	for(int i=0;i<9;++i) {
		if(i%4!=0)continue;
		if(w[i]==0)continue;
		vec v;v.tail0=i;v.tail1=-1;
		temp[++tail]=v;
	}
	for(int i=0;i<=9;++i) {
		for(int j=0;j<=9;++j) {
			if((10*j+i)%4!=0)continue;
			vec v=w;
			v[i]--;v[j]--;v.tail0=i;v.tail1=j;
			if(v[i]<0 || v[j]<0)continue;
			temp[++tail]=v;
		}
	}
	sort(temp+1,temp+tail+1);
	if(tail==0) {
		printf("-1\n");
	}else {
		temp[tail].show();
	}
	return 0;
}
int main() {
	int t;scanf("%d",&t);
	while(t-->0)doing();
	return 0;
} 