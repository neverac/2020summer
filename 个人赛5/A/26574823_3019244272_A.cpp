#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b){
	return a ? gcd(b % a, a) : b;
}
ll ksm(ll a, ll b, ll mod){
	ll s = 1;
	while(b){
		if(b & 1) s = s * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return s;
}
ll work(ll n, ll m){
	if(m == 1) return 0;
	if(n == 4) return 262144 % m;
	if(n == 3) return 9 % m;
	if(n == 2) return 2 % m;
	if(n == 1) return 1 % m;
	ll phi = m, tmp = m;
	for(ll i = 2; i * i <= tmp; i++){
		if(tmp % i == 0){
			phi -= phi / i;
			while(tmp % i == 0){
				tmp /= i;
			}
		}
	}
	if(tmp != 1) phi -= phi / tmp;
	ll t = work(n - 1, phi);
	if(gcd(n, m) == 1) return ksm(n, t, m);
	else return ksm(n, t + phi, m);
}
int main(){
	ll n, m;
	cin >> n >> m;
	cout << work(n, m) << endl;
	return 0;	
}