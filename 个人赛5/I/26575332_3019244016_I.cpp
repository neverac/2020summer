#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    //ios::sync_with_stdio(0);
    while (t--) {
        string s;
        cin >> s;
        vector<int> a, b;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if ((s[i] - '0') & 1) a.push_back(s[i] - '0');
            else b.push_back(s[i] - '0');
        }
        int i = 0, j = 0;
        int A = a.size(), B = b.size();
        while (i < A && j < B) {
            if (a[i] < b[j]) s[i+j] = a[i] + '0', i++;
            else s[i+j] = b[j] + '0', j++;
        }
        while (i < A) {
            s[i+j] = a[i] + '0', i++;
        }
        while (j < B) {
            s[i+j] = b[j] + '0', j++;
        }
        cout << s << endl;
    }
}
