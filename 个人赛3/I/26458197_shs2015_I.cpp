#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
char str[110];
int main(){
	int N;
	scanf("%d",&N);
	scanf("%s",str+1); 
	int now = 0;
	int mn = 0;
	int ans = 10000;
	for(int i = 1;i <= N;i++){
		if(str[i] == '-'){
			now--;
		}
		else now++;
		mn = min(now,mn); 
	}
	ans = abs(mn) + now;
	printf("%d\n",ans);
	return 0;
} 