#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
int N;
const int SIZEN = 110;
char str[SIZEN] = {0};
int a[SIZEN] = {0};
void work(){
	scanf("%d",&N);
	for(int i = 1;i <= N;i++)scanf("%d",&a[i]);
	for(int i = 1;i <= 51;i++)str[i] = 'a';str[52] = '\0';
	puts(str+1);
	for(int i = 1;i <= N;i++){
		if(str[a[i] + 1] == 'a')str[a[i] + 1] = 'b';
		else str[a[i] + 1] = 'a';
		puts(str+1);		
	}
}

int main(){
	int T;scanf("%d",&T);
	while(T--)work();
	return 0;
}
/*
4
4
1 2 4 2
2
5 3
3
1 3 1
3
0 0 0
*/