#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int n;
string s;
string t;
struct INT{
    int n;
    int a[1005];
    INT () {n = 1, a[1]= 0;}
    INT (string s) {
        n = s.size();
        for (int i = 0; i < n; i++) {
            a[n-i] = s[i] - 'a';
        }
        while (n >= 1 && a[n] == 0) n--;
    }
    bool operator <(INT x) {
        if (n != x.n) return n < x.n;
        for (int i = n; i >= 1; i--) {
            if (a[i] != x.a[i]) return a[i] < x.a[i];
        }
        return 0;
    }
    bool operator == (INT x) {
        if (n != x.n) return 0;
        for (int i = 1; i <= n; i++) if (a[i] != x.a[i]) return 0;
        return 1;
    }
    bool operator > (INT x) {
        if (n != x.n) return n > x.n;
        for (int i = n; i>= 1; i--) {
            if (a[i] != x.a[i]) return a[i] > x.a[i];
        }
        return 0;
    }


};
struct frag{
    int type;
    string s;
    INT a;
    bool operator <(frag x) {
        if (type != x.type) return type < x.type;
        if (type == 0) return a < x.a;
        if (type == 1) return s < x.s;
        return 0;
    }
    bool operator == (frag x) {
        return (type == x.type && a == x.a && s == x.s);
    }
};
vector<frag>a, b;



void process(string s, vector<frag> &a) {
    int n = s.size();
    int last = 0;
    for (int i = 0; i < n; i++) {
        if (isdigit(s[i])) {
            if (last <= i - 1) {
                a.push_back({1, s.substr(last, i - last), INT()});
            }
            int j = i;
            while (j + 1 < n && isdigit(s[j+1])) j++;
            a.push_back({0, string(), INT(s.substr(i, j - i + 1))});
            last = j + 1;
            i = j;
        }
    }
    if (last <= n - 1) {
        a.push_back({1, s.substr(last, n - last), INT()});
    }
}

bool judge(vector<frag> x, vector<frag> y) {
    int n = x.size(), m = y.size();
    int g = min(n, m);
    for (int i = 0; i < g; i++) {
        if (x[i] == y[i]) continue;
        return x[i] < y[i];
    }
    return m > n;
}
int main() {
    int n;
    cin >> n;
    cin >> s;
    process(s, a);
    for (int i = 1; i <= n; i++) {
        b = vector<frag>();
        cin >> t;
        process(t, b);
        if(judge(b, a)) puts("-");
        else puts("+");
    }
}
