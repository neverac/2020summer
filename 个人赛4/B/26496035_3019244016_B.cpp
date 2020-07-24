
#include <iostream>
using namespace std;
const int mod = 4;
int read() {
    char ch;
    while (!isdigit(ch = getchar()));
    int res = ch - '0';
    while (isdigit(ch = getchar())) res = (res * 10 + (ch & 15)) % mod;
    return res;
}
int qpow(int x,int y) {
    int res = 1;
    while (y) {
        if (y&1) res = res * x % 5;
        x = x * x % 5;y>>=1;
    }
    return res;
}

int main() {
    int n;
    n = read();
    n %= 4;
    int ans = 0;
    for (int i = 1; i <= 4; i++) ans+=qpow(i,n);
    cout<< ans%5<<endl;
}
