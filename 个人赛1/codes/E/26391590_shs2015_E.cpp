#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
const int SIZEN = 100010;
int N;
int A[SIZEN] = {0};
int a[SIZEN] = {0};
bool flag[SIZEN] = {0};
void work(){
	scanf("%d",&N);
	for(int i = 1;i <= N;i++)flag[i] = false;
	for(int i = 1;i <= N;i++)a[i] = 0;
	for(int i = 1;i <= N;i++){
		scanf("%d",&A[i]);
		if(A[i] != A[i-1]){
			a[i] = A[i];
			flag[a[i]] = true;
		}
	}
	int now = 1;
	for(int i = 1;i <= N;i++){
		if(flag[i])continue;
		while(a[now])now++;
		a[now] = i;
	}
	int mx = 0;
	for(int i = 1;i <= N;i++){
		mx = max(mx,a[i]);
		if(mx != A[i]){
			puts("-1");
			return;
		}
	}
	for(int i = 1;i <= N;i++)printf("%d ",a[i]);printf("\n");
}
int ans[100010] = {0},cnt = 0;
int main(){
	long long N;
	scanf("%lld",&N);
	while(N){
		ans[++cnt] = N % 26;
		N /= 26;
	}
	for(int i = 1;i < cnt;i++){
		if(ans[i] <= 0)ans[i] += 26,ans[i+1]--;
	}
	while(ans[cnt] == 0)cnt--;
	for(int i = cnt;i >= 1;i--){
		printf("%c",ans[i] + 'a'-1);
	}
	
}
/*
26
*/