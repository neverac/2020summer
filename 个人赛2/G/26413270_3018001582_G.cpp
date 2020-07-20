#include <cstdio>
#include <cstring>
#include <algorithm>
#include<iostream>

using namespace std;

int num[100005];

int main() {
    int n, k;
    cin >> n>>k;
    int a = 1, b = n - 1;
    num[1] = 1;
    for (int i = 2; i <= n; ++i) {
        int res = a * b;
        num[i] = num[i - 1] + res;
        --b;
        a *= -1;
    }
    for (int i = 1; i <= k; ++i) {
        printf("%d ", num[i]);
    }
    int ans = num[k];
    if (k % 2) {
        for (int i = k + 1; i <= n; ++i)
            printf("%d ", ++ans);
    }
    else {
        for (int i = k + 1; i <= n; ++i)
            printf("%d ", --ans);
    }
    cout << endl;
    return 0;
}