#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
const int SIZEN = 200010;
int N;
typedef long long LL;
LL a[SIZEN];
char str[SIZEN] = {0};
int nx[SIZEN][10] = {0};
int sum[10] = {0};
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%s",str+1);
		int n = strlen(str+1);
		int ans = n-2;
		for(int i = 0;i <= 9;i++)nx[n+1][i] = 0,sum[i] = 0;
		for(int i = 1;i <= n;i++)sum[str[i] - '0']++;
		for(int i = 0;i <= 9;i++)ans = min(ans,n-sum[i]);
		for(int i = n;i >= 1;i--){
			for(int j = 0;j <= 9;j++)nx[i][j] = nx[i+1][j];
			nx[i][str[i]-'0'] = i;
		}
		for(int i = 0;i <= 9;i++){
			for(int j = 0;j <= 9;j++){
				if(i == j)continue;
				int sum = 0;
				int now = 1;
				while(now){
					//if(i == 2 && j == 5)printf("now = %d,sum = %d\n",now,sum);
					now = nx[now][i];
					if(!now)break;
					now = nx[now][j];
					if(!now)break;
					sum += 2;
				}
				ans = min(ans,n-sum);
			
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
3
95831
100120013
252525252525
*/