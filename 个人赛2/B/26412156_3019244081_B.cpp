#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<ctime> 
#define ll long long
using namespace std; 
const int N=1e5 + 100;
const double eps=1e-10;
bool vis[70000];
char ans[50];
int main(){
	int A,B,C,S;
	int a=0,b=131071;
	scanf("%d",&A);
	while(A!=0){
		scanf("%d%d%d",&B,&C,&S);
		a=0;b=131071;
		memset(vis,false,sizeof(vis));
		while(!vis[S]){
			vis[S]=true;
			a=a | S;
			b=b & S;
			S=((A%C)*(S%C)+B)%C;
			//printf("S:%d  ",S);
		}
		for(int i=1;i<=16;i++) ans[i]='?';
		//printf("\n%d %d\n",a,b);
		for(int i=16;i>=1;i--){
			if(b%2==1) ans[i]='1';
			b>>=1;
		}
		for(int i=16;i>=1;i--){
			if(a%2==0) ans[i]='0';
			a>>=1;
		}
		for(int i=1;i<=16;i++) printf("%c",ans[i]);
		printf("\n");
		scanf("%d",&A);
	}
	
	
	return 0;
}