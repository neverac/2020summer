#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

typedef pair<string, int> PR;
PR text[1000];

bool cmp(PR A, PR B) {
	return A.second < B.second;
}

int main() {
	int n, m;
	cin >> n >> m;
	string a;
	int index = 0;
	for (int i = 0; i < m; ++i) {
		cin >> a;
		bool tag = 1;
		for (int j = 0; j < 1000; ++j) {
			if (text[j].first == a) {
				tag = 0;
				break;
			}
		}
		if (tag) {
			text[index].first = a;
			text[index++].second = a.length();
		}
	}
	int ans = 0,cnt = 0;
	sort(text, text + index,cmp);
	for (int i = 0; i < index; ++i) {
		if (ans) cnt++;
		if (cnt + text[i].second <= n) {
			ans++;
			cnt += text[i].second;
		}
		else break;
	}
	cout << ans << endl;
	return 0;
}