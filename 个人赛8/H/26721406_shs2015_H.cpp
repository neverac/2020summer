#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int SIZEN = 200010;
int a[SIZEN];
int left[SIZEN];
int right[SIZEN];
int N;
int main(){
	scanf("%d",&N);
	for(int i = 1;i <= N;i++)scanf("%d",&a[i]);
	right[N] = 1;
	for(int i = N-1;i >= 1;i--){
		if(a[i] < a[i+1])right[i] = right[i+1] + 1;
		else right[i] = 1;
	}
	left[1] = 1;
	for(int i = 2;i <= N;i++){
		if(a[i] > a[i-1])left[i] = left[i-1] + 1;
		else left[i] = 1;
	}
	int ans = 0;
	for(int i = 2;i < N;i++){
		if(a[i-1] < a[i+1])ans = max(ans,left[i-1] + right[i+1]);
	}
	for(int i = 1;i <= N;i++)ans = max(ans,left[i]),ans = max(ans,right[i]);
	printf("%d\n",ans);
	return 0;
}
/*
7
6 5 4 3 2 4 3

4
1 2 1 3
*/