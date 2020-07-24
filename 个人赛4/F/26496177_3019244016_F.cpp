#include <iostream>
using namespace std;

int main() {
    int n, k, s, p;
    cin >> k >>n >> s >> p;
    n = (n + s - 1) / s * k;
    p = (n + p - 1) / p;
 //   cout << n << endl;
    cout << p << endl;
}
