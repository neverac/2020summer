#include<stdio.h>
#include<string.h>
#include<string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#define ll long long 
#define N 1000010
#define mid (l+r)/2
#define lc (x<<1)
#define rc (x<<1)|1
#define tozero(x) memset(x,0,sizeof x);
#define INF 0x3f3f3f3f
const ll mod = 1e9+7;
using namespace std;


ll a, b;

int main()
{
	cin >> a >> b;
	if(a == b){
		cout <<1<< endl;
		return 0;
	}
	ll ans = (ll)(a/b), now = 0;
	a -= ans * b;
	while(1) {
		if(a == 1){
			ans += b;
			break;
		}
		if(b == 1){
			ans += a;
			break;
		}
		now += (ll)(b / a);
		b %= a;
		ll tmp = a;
        a = b;
        b = tmp;
	}
	cout << ans + now << endl;
	return 0;
}