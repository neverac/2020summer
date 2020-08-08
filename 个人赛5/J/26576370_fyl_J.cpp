#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char s[20],ch[20];

int main(){

	while(1){
		scanf("%s",s);
		if(s[0]=='e') break;

		
		printf("? 0 1\n");fflush(stdout);
		scanf("%s",ch);
		if(ch[0]=='x'){
			
			printf("! 1\n");fflush(stdout);
			continue;
		}
		
		int i=1,j=2;
		for(;;i*=2,j*=2){
			
			printf("? %d %d\n",i,j);fflush(stdout);
			scanf("%s",ch);
			if(ch[0]=='x') break;
		}		
		int l=i+1,r=j;
		while(l<r){
			int mid=(l+r)/2;
			
			printf("? %d %d\n",mid,r);fflush(stdout);
			scanf("%s",ch);
			if(ch[0]=='y') r=mid;
			if(ch[0]=='x') l=mid+1;
		}
		
		printf("! %d\n",l);fflush(stdout);
	}

}