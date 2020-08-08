#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<cstring>
#include<set>
#include<cmath>
#include<queue>
#include<sstream>
#include<algorithm>
#include<cstring>

using namespace std;
const int Maxn = 1e2 + 10;
int a[Maxn], b[Maxn];

int main() {
#ifndef ONLINE_JUDGE
    freopen("/Users/ttjy/Desktop/in.txt", "r", stdin);
#endif
    clock_t c1 = clock();
    //======================================
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &b[i]);
    }
    int i = 0, j = 0;
    for (; j < n && i < n;) {
        while (a[i] < b[j]&&i < n)i++;
        while (b[j] < a[i]&&j < n)j++;
    }
    cout << max(n-i, n-j) << endl ;
    //======================================
    std::cerr << "Time:" << clock() - c1 << "ms" << std::endl;
    return 0;
}
