#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>

using namespace std;

char s[100010];
int qk_pow(int a,int b){
	int p=1;
	for(;b;b>>=1,a=(a*a)%5)
		if(b&1) p=(p*a)%5;
	return p;
}

int main(){
	scanf("%s",s);
	int n=strlen(s);
	int num=0;
	for(int i=0;i<n;i++){
		int x=s[i]-'0';
		num=(num*10+x)%4;
	}
	int ans=1;
	for(int i=2;i<=4;i++)
		ans=(ans+qk_pow(i,num))%5;
	printf("%d\n",ans);
	return 0;
}