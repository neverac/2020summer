#include<cstring>
#include<cstdio>
using namespace std;

char str[100005];
int pos[100005];

int main() {
	int k;
	scanf("%d", &k);
	scanf("%s", str);
	long long ans = 0;
	int L = strlen(str);
	for (int i = 0; i < 26; ++i){
		int cnt = 0;
		for (int j = 0; j < L; ++j) {
			if(str[j]-'a'==i)
				pos[cnt++] = j;

			if (!cnt) continue;
			if (cnt <= k) ans += pos[cnt - 1] + 1;
			else ans += pos[cnt - 1] - pos[cnt - 1 - k];
		}
	}
	printf("%lld\n", ans);
	return 0;
}


//a *** a ** a a ****** a