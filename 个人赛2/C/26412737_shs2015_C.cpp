#include <cstdio>
#include <cstring>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long LL;
char str[100];
LL hemax[100];
LL turn(char x){return x - '0';}
void work(int x){
	scanf("%s",str+1);
	int n = strlen(str+1);
	for(int i = 1;i <= n;i++)hemax[i] = 0;
	LL now = str[1] - '0';
	for(int i = 2;i <= n-3;i++){
		now = now * 10 + str[i] - '0';
		LL pw = 1;
		for(int j = 1;j < i;j++){
			pw *= 10;
			hemax[i]  = max(hemax[i],now % pw + now/pw);
		}
	}
	LL ans = -LLONG_MAX;
	for(int i = 2;i <= n-5;i++)ans = max(ans,hemax[i]);
	ans = max(ans,hemax[n-3] - (str[n-2] - '0') * (str[n-1] - '0') / (str[n] - '0'));
	if(n >= 6){
		ans = max(ans,hemax[n-4] - turn(str[n-3]) * turn(str[n-2])/(turn(str[n-1]) * 10 + turn(str[n]))   );
	}
	printf("Case #%d: %lld\n",x,ans);
}
int main(){
	int T;scanf("%d",&T);
	for(int i = 1;i <= T;i++)work(i);
	return 0;
}
/*
1
12345
*/