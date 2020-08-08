#include <cstdio>
#include <cstring>
//又是一道原题 
typedef long long ll;
int n, m;
ll euler(int n) {
      ll ans = n;
      for(int i = 2; i * i <= n; i++) {
         if(n % i == 0) {
             ans = ans / i * (i - 1);
             while(n % i == 0) n /= i;
         }
     }
     if(n > 1) ans = ans / n * (n - 1);
     return ans;
 }
 ll ModPow(int x, int p, ll mod) {
     ll rec = 1;
     while(p > 0) {
         if(p & 1) rec = (ll)rec * x % mod;
         x = (ll)x * x % mod;
         p >>= 1;
     }
     return rec;
 }
 ll slove(int n, ll m) {
     if(m == 1) return 0;
     if(n == 1) return 1 % m;
     if(n == 2) return 2 % m;
     if(n == 3) return 9 % m;
     if(n == 4) return (1 << 18) % m;
     return (ll)ModPow(n, euler(m), m) * ModPow(n, slove(n - 1, euler(m)), m) % m;
 }
 int main() {
     scanf("%d%d", &n, &m);
         printf("%lld\n",slove(n, m));
     return 0;
 }