#include<bits/stdc++.h>
using namespace std;
int pre[100005];
void init() {
	for (int i = 0; i < 100005; i++) {
		pre[i] = i;
	}
}
int find(int x) {
	if (pre[x] == x) return x;
	else {
		pre[x] = find(pre[x]); return pre[x];
	}

}
int main() {
	int a, b,ans=0,k,x;
	init();
	cin >> k >> x;
	for (int i = 0; i < x; i++) {
		scanf("%d %d", &a, &b);
		if (find(a) == find(b)) {
			ans++;
		}
		pre[find(a)] = find(b);
	}
	cout << ans;
	return 0;
}