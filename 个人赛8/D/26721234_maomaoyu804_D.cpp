#include <bits/stdc++.h>
using namespace std;
char s[205];

int main(){
	int t;scanf("%d",&t);
	while(t--){
		for(int i=0;i<200;i++) s[i]='a';
		int n;scanf("%d",&n);
		printf("%s\n",s);
		int cnt=1;
		int temp;
		for(int i=0;i<n;i++){
			int num;scanf("%d",&num);
			if(s[num]=='a') s[num]='b';
			else s[num]='a';
			//s[num]=char('a'+cnt);
			cnt=(cnt+1)%2;
			printf("%s\n",s);
		}
	}
	return 0;
}