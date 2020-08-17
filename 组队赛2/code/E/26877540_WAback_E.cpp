#include <bits/stdc++.h>
#define ll long long
using namespace std;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48,ch=getchar();}
	return x*f;
}
int main(){
	int t=read();
	while(t--){
		int k=read(),l=read();
		if(l>=2000){
			puts("-1");
			continue;
		}
		printf("1999\n");
		int one=(k+1999)/1998,sum=k+1999;
		printf("-1 ");
		for(int i=1;i<=1997;i++) printf("%d ",one),sum-=one;
		printf("%d\n",sum);
	}
	return 0;
}
/*
3
8 3
612 7
4 2019

*/