#include <bits/stdc++.h>
using namespace std;
int const maxn=65;
int r,c,nu1,nu2;
char s[maxn][maxn];
bool check=false;
bool getlie(){
	bool flag1=true,flag2=true;
	for(int i=0;i<c;i++){
		if(s[0][i]=='P'){flag1=false;}
		else check=true;
		if(s[r-1][i]=='P'){flag2=false;}
		else check=true;
	}
	if(flag1||flag2)return true;
	flag1=true,flag2=true;
	for(int i=0;i<r;i++){
		if(s[i][0]=='P'){flag1=false;}
		else check=true;
		if(s[i][c-1]=='P'){flag2=false;}
		else check=true;
	}
	if(flag1||flag2)return true;
	return false;
}
bool cun(){
	int g=r-1;
	for(int i=1;i<g;i++){
		bool flag1=true;
		for(int j=0;j<c;j++){
			if(s[i][j]=='P'){flag1=false;}
		}
		if(flag1){
			return 1;
		}
	}
	g=c-1;
	for(int i=1;i<g;i++){
		bool flag1=true;
		for(int j=0;j<r;j++){
			if(s[j][i]=='P'){flag1=false;}
		}
		if(flag1){
			return 1;
		}
	}
	return 0;
}
void work(){
	if(nu1==0){
		printf("MORTAL\n");return ;
	}
	if(nu2==0){
		printf("0\n");return ;
	}
	if(getlie()){
		printf("1\n");return ;
	}
	if(s[0][0]=='A'||s[0][c-1]=='A'||s[r-1][0]=='A'||s[r-1][c-1]=='A'||cun()){
		printf("2\n");return ;
	}
	if(check){
		printf("3\n");return ;
	}
	printf("4\n");
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		nu1=0;nu2=0;
		check=false;
		scanf("%d%d",&r,&c);
		for(int i=0;i<r;i++){
			scanf("%s",s[i]);
			for(int j=0;j<c;j++){
				if(s[i][j]=='A')nu1++;
				else nu2++;
			}
		}
		work();
	}
	return 0;
}
/*
10
4 4
PAPP
PAPP
PAPP
PAPP

5 4
PPPP
PPPP
AAAA
PPPP
PPPP

3 5
AAAAA
AAAAA
AAAAA

4 4
APPP
PPPP
PPPP
PAPP

4 4
PPPA
PPPP
PPPP
PAPP

4 4
PPPP
PPPP
PPPP
APPP
*/