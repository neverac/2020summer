#include<bits/stdc++.h>
/*
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<ctime> 
*/
#define ll long long
using namespace std; 
const int N=1e5 + 100;
const double eps=1e-10;

int a[3*N],b[3*N];//ÆæÅ¼
int ans[3*N];
int cnt1,cnt2;
char x;
int main(){
	int T;
	scanf("%d",&T);
	char x;
	while(T--){
		scanf("\n");
		scanf("%c",&x);
		cnt1=0,cnt2=0;
		while(x!='\n'){
			int xx=(int)(x-'0');
			if(xx%2==0) b[++cnt2]=xx;
			else a[++cnt1]=xx;
			scanf("%c",&x);
		}
		int n=0,i=1,j=1;
		while(i<=cnt1 && j<=cnt2){
			//printf("?%d %d\n",a[i],b[j]);
			if(a[i]<b[j]){
				ans[++n]=a[i];
				i++;
			}
			else{
				ans[++n]=b[j];
				j++;
			}
			//printf("=%d\n",ans[n]);
		}
		for(int ii=i;ii<=cnt1;ii++) ans[++n]=a[ii];
		for(int jj=j;jj<=cnt2;jj++) ans[++n]=b[jj];
		for(int i=1;i<=n;i++) printf("%d",ans[i]);
		printf("\n");
	}
	return 0;
}