#include <iostream>
#include <cstdio>
using namespace std;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        cnt += (x + k - 1) / k;
    }
    cnt = (cnt + 1) / 2;
    printf("%d\n", cnt);
}