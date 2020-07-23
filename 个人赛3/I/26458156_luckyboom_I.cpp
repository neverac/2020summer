#include <bits/stdc++.h>
using namespace std;

char ch[105];
int main(){
	int n,tot=0;
	scanf("%d",&n);
	scanf("%s",ch);
	for(int i=0;i<n;i++){
		if(ch[i]=='-'){
			if(tot>0)tot--;
		}
		else tot++;
	}
	printf("%d\n",tot);
}