#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 205;

int a[N];
int n;
string s;



void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    s.resize(100);
    for (int i = 0; i < 100; i++) s[i] = 'a';
    cout << s << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = a[i]; j <= a[i]; j++) {
            s[j]++;
            if (s[j] > 'z') s[j] = 'a';
        }
        cout << s << endl;
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) solve();
}