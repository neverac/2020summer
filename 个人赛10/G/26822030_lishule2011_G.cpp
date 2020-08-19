#include<bits/stdc++.h>

using namespace std;
const int maxn = 100005;

struct node {
    int id;
    int num;
} a[maxn], c[maxn];


bool cmp1(node a, node b) {
    return (a.num > b.num) || (a.num == b.num && a.id < b.id);
}

bool cmp2(node a, node b) {
    return a.id < b.id;
}

int n;

void read() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int r;
        cin >> r;
        a[i].id = i;
        a[i].num = r;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    read();
    sort(a + 1, a + n + 1, cmp1);
    int t;
    cin >> t;
    while (t--) {
        int len, pos;
        cin >> len >> pos;
        for (int j = 1; j <= len; j++)
            c[j] = a[j];

        sort(c + 1, c + len + 1, cmp2);

//        for (int i=1;i<=len;i++) cout << c[i]<<endl;
        cout << c[pos].num << endl;
    }
    return 0;
}
