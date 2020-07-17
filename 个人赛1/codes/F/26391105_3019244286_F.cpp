#include<iostream>
#include<map>
using namespace std;
typedef long long ll;

map<int, int>seq;
map<int, int>::iterator it;
int main() {
	int n;
	scanf("%d", &n);
	int temp;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		sum += temp;
		seq[temp]++;
	}
	int Q, B, C;
	scanf("%d", &Q);
	for (int i = 0; i < Q; i++) {
		scanf("%d%d", &B, &C);
		it = seq.find(B);
		if (it != seq.end()) {
			sum += (C - B) * (it->second);
			seq[C] += it->second;
			it->second = 0;
		}	
		printf("%lld\n", sum);
	}
	return 0;
}