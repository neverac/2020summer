#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

char s[1000100];
int main(){
	int n;
	scanf("%d",&n);
	scanf("%s",s);
	int sum=0,num=0,mn=0x7f7f7f7f;
	for(int i=0;i<n;i++){
		if(s[i]=='-') sum--;
		else sum++;
		mn=min(mn,sum);
	}
	if(mn<0) num=-mn;
	for(int i=0;i<n;i++){
		if(s[i]=='-') num--;
		else num++;
	}
	printf("%d\n",num);
}