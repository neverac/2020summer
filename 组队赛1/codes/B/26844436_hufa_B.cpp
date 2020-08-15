#include <iostream>
#include <stdio.h>
#include<cmath>
#include<cctype>
#include<cstdio>
#include <algorithm>
#include <string.h>
#include <string>
#include<math.h>
#include<map>
#include<unordered_map>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define ll long long
#define inf 0x3f3f3f3f
#define Maxn 130000
#define max(a,b) a>b?a:b
using namespace std;

const int N = 2e5 + 5;
const ll mod = 998244353;
ll a[5020], ml[5020][5020];

int main() {

	int t;
	scanf("%d",&t);
	for(int i=1; i<=t; i++) {
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+t+1);
	for (int i = 1; i <= t; i++) {
		for (int j = 1; j <= t; j++) {
			ml[i][j] = 2;
		}
	}
	int maxx = 2;
	for (int i=2; i<=t-1; i++) {
		int l = i-1, r = i+1;
		while (l >= 1 && r <= t) {
			if (a[l]+a[r] == a[i]*2) {
				ml[i][r] = ml[l][i] + 1;
				maxx = max(maxx,ml[i][r]);
				l--;
				r++;
			}
			else if (a[l]+a[r] <a[i]*2) {
				r++;
			}
			else {
				l--;
			}
		}
	}
	printf("%d\n",maxx);
	return 0;
}
