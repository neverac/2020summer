#include<bits/stdc++.h>
using namespace std;
int main() {
	int sum; int num,s1=0,s2=0;
	cin >> sum;
	for (int i = 0; i < sum; i++) {
		scanf("%d", &num);
		if (num == 2) s2++;
		else s1++;
	}
	int ans[200005]={0};int ans_i=0;
	if (s2) {
		if (s1 && s2) {
			ans[0]=2;ans[1]=1; s1--; s2--;ans_i+=2;
			while (s2) {
				ans[ans_i]=2; s2--;ans_i++;
			}
			while (s1) {
				ans[ans_i]=1; s1 -= 1;ans_i+=1;
			}
// 			if (s1) {ans[ans_i]=1;ans_i++;}
		}
		else 
		while (s2) {
				ans[ans_i]=2; s2--;ans_i++;
			}
	}
	else {
		if (s1 > 1) {
			ans[0]=1; s1--;ans_i++;
			while (s1) {
				ans[ans_i]=1; s1--;ans_i++;
			}
		}
		else ans[0]=1;
	}
	for(int i = 0; i<sum; i++) printf("%d%c",ans[i],i == sum-1 ? '\n' :' ');
	return 0;
}