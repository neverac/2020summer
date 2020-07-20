#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 65536;
bool vis[maxn];
int main(){
	long long A, B, C, X;
	while(cin >> A && A){
		cin >> B >> C >> X;
		long long yu = 65535, hu = 0;
		yu &= X;
		hu |= X;
		vis[X] = true;
		while(1){
			X = (A * X + B) % C;
			if(vis[X]) break;
			yu &= X;
			hu |= X;
			vis[X] = true;
		}
		for(long long t = 32768; t; t >>= 1){
			if(yu & t) cout << 1;
			else{
				if(hu & t) cout << '?';
				else cout << 0;
			}
		}
		cout << endl;
		memset(vis, false, sizeof vis);
	}
	return 0;
}