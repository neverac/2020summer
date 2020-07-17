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
#include<queue>
#define ll long long
using namespace std;
const int N=1e5 + 100;
const double eps=1e-10;
int a[N];
int ans[N];
bool vis[N];
int main(){
	int T;
	int n;
	scanf("%d",&T);
	bool flag=false;
	while(T--){
		priority_queue <int> pq;
		scanf("%d",&n);
		//printf("OK");
		int pre=0; 
		flag=false;//²»¿ÉÄÜ 
		//memset(vis,false,sizeof(vis));
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]>pre){
				for(int j=pre+1;j<a[i];j++) pq.push(j);
				ans[i]=a[i];
				pre=a[i];
			}
			else if(a[i]<pre){
				flag=true;
				//break;
			}
			else{//==
				if(!pq.empty()){
					ans[i]=pq.top();
					pq.pop();	
				}
				else{
					flag=true;
					//break;
				}
			}
		}
		while(!pq.empty()) pq.pop();
		if(flag) printf("-1\n");
		else{
			for(int i=1;i<=n;i++) printf("%d ",ans[i]);
			printf("\n");
		}
	}
	return 0;
}