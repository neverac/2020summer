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

char s[2*N];
int main(){
	int T;
	scanf("%d",&T);
	int len;
	int ans;
	int sum=0;
	while(T--){
		scanf("%s",s+1);
		len=strlen(s+1);
		ans=len+1;
		for(int i=0;i<=9;i++){
			sum=0;
			for(int j=1;j<=len;j++){
				if(s[j]=='0'+i) sum++;
			}
			ans=min(ans,len-sum);
		}
		for(int i=0;i<=9;i++){
			for(int j=0;j<=9;j++){
				if(i==j) continue;
				sum=0;
				for(int k=1;k<=len;k++){
					if(sum%2==0 && s[k]=='0'+i) sum++;
					if(sum%2==1 && s[k]=='0'+j) sum++;
				}
				if(sum%2==1) sum--;
				ans=min(ans,len-sum);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}