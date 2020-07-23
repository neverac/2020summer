#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;


const int maxn = 400010;

int prim[maxn],tot;
bool vis[maxn];
void get_prim(int n){
	for(int i=2;i;i++){
		if(!vis[i]){
			prim[++tot]=i;
			if(i>n) return;
		}
		for(int j=1;j<=tot&&i*prim[j]<=n;j++){
			vis[i*prim[j]]=1;
			if(i%prim[j]==0) break;
		}
	}
}
int num[3];
int main(){
	int n;
	scanf("%d",&n);
	get_prim(2*n);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		num[x]++;
	}
	int now=0,cnt=1;
	for(int i=1;i<=n;i++){
		//printf("cnt = %d\n",cnt);
		if(prim[cnt]-now==1&&num[1]){
			printf("1 ");
			now++,cnt++,num[1]--;
			continue;
		}
		if(num[2]) now+=2,num[2]--,printf("2 ");
		else now++,num[1]--,printf("1 ");
		if(now>=prim[cnt]) cnt++;
	}puts("");
}