#include <iostream>
using namespace std;
int n;
int a[55];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int flag = 1;
    for (int i = 1; i<= n; i++) {
        for (int j = 1; j <=  n; j++) {
            for (int k = 1; k <= n; k++) {
                if (i == j || j == k || i == k) continue;
                int b = a[i] - a[j];
                if (b % a[k] != 0) flag = 0;
            }
        }
    }
    if (flag) puts("yes");
    else puts("no");
}