#include<bits/stdc++.h>
using namespace std;
#define MAXN 100010
int A[MAXN],B[MAXN],N; 
int main(){
	scanf("%d",&N);
	for (int i=1; i<=N; i++) scanf("%d",&A[i]);
	for (int i=1; i<=N; i++) scanf("%d",&B[i]);
	int cnt1 = 1, cnt2 = 1;
	while (cnt1<=N && cnt2<=N){
		if (A[cnt1] > B[cnt2]) cnt2++;
		else cnt1++;
	}
	int ans = 1; 
	if (cnt1>N) ans = N-cnt2+1;
	else ans = N-cnt1+1;
	printf("%d\n",ans);
	return 0;
}