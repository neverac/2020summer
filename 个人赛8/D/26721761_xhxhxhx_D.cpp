#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

const int MAX_N = 128;

int main()
{
    int T, N, A;
    cin >> T;
    while (T--)
    {
        string s0, s1;
        cin >> N;
        s0.assign(MAX_N, 'x');
        cout << s0 << endl;
        for (int i = 0; i < N; i++)
        {
            cin >> A;
            s1 = s0.substr(0, A) + string(MAX_N - A, s0[A] ^ 1);
            cout << s1 << endl;
            s0.swap(s1);
        }
    }
    return 0;
}