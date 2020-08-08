#include<iostream>
#include<cstdio>
using namespace std;
int fa[100005];
bool comp(char a,char b){
	return a>=b;	
}

void init(){
    for(int i=0;i<100005;i++){
        fa[i]=i;
    }
}
int find(int x){
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main(){
	init();
	int n,k,ans=0;
	scanf("%d%d",&n,&k);
	while(k--){
		int a,b;
		scanf("%d%d",&a,&b);
		a=find(a);
		b=find(b);
		if(a==b){
            ans++;
        }
		fa[a]=b;
	}
	printf("%d\n", ans);
	return 0;
}
