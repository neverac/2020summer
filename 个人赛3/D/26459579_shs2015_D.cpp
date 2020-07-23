#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
const int SIZEN = 400010;
int prime[SIZEN],tot = 0;
bool vis[SIZEN] = {0};
void Prime(){
	for(int i = 2;i <= 400000;i++){
		if(!vis[i])prime[++tot] = i;
		for(int j = 1;j <= tot && prime[j] * i <= 400000;j++){
			vis[i * prime[j]] = true;
			if(i % prime[j] == 0)break;
		}
	}
}
int two = 0,one = 0;
int main(){
	Prime();
	int N;scanf("%d",&N);
	for(int i = 1;i <= N;i++){
		int x ;scanf("%d",&x);
		if(x == 1)one++;
		else two++;
	}
	int sum = 0;
	int p = 1;
	for(int i = 1;i <= N;i++){
		if(prime[p] - sum >= 2){
			if(two)printf("2 "),two--,sum+=2;
			else printf("1 "),one--,sum++;
		}
		else {
			if(one)printf("1 "),one--,sum++;
			else printf("2 "),two--,sum+=2;
		}
		if(sum == prime[p] && p <= tot)p++;
		while(sum > prime[p] && p <= tot)p++;
	}
	return 0;
} 