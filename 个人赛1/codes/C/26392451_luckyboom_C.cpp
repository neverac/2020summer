#include <bits/stdc++.h>
using namespace std;
int  n;
int const maxn=1e5+7;
bool vis[maxn];
int a[maxn],p[maxn];
inline int get_num(){
	char ch;
	int num=0;
	ch=getchar();
	while(ch<'0'||ch>'9'){ch=getchar();}
	while(ch>='0'&&ch<='9'){num=(num<<3)+(num<<1)+ch-'0';ch=getchar();}
	return num;
}
void work(){
	a[1]=p[1];
	vis[a[1]]=true;
	for(int i=2;i<=n;i++){
		if(p[i]!=p[i-1]){
			a[i]=p[i];
			vis[a[i]]=true;
		}
	}

	for(int i=2,q=1;i<=n;i++){
		if(!a[i]){
			while(vis[q]){
				q++;
			}
			a[i]=q;
			vis[q]=true;
		}
	}
	for(int i=1;i<n;i++)printf("%d ",a[i]);
	printf("%d\n",a[n]);
}
int main(){
	int t;
	t=get_num();
	while(t--){
		n=get_num();
		bool flag=true;
		p[1]=get_num();
		vis[1]=0;
		a[1]=0;
		for(int i=2;i<=n;i++){
			vis[i]=0;
			a[i]=0;
			p[i]=get_num();
			if(p[i]<i)flag=false;
		}
		if(flag)work();
		else{
			printf("-1\n");
		}
	}
	return 0;
}