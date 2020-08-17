#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int SIZEN = 100;
typedef long long LL;
#define mid ((l+r) >> 1)
int N,M;
int a[SIZEN];
int main(){
	scanf("%d",&N);
	for(int i = 1;i <= N;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+N);
	bool flag = false;
	for(int i = 1;i <= N;i++){
		for(int j = 1;j <= N;j++){
			for(int k = 1;k <= N;k++){
				if(i == j || j == k || i == k)continue;
				if((a[k] - a[j] ) %a[i] != 0){
					flag= true;
				}
			}
		}
	}
	if(flag)puts("no");
	else puts("yes");
	return 0;
} 