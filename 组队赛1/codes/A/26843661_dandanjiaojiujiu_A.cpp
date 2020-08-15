#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int MAX_I = 1000000000;

struct P
{
    vector<int> v;
    P(const string &str)
    {
        size_t cur = 0, cnt;
        while (cur < str.length())
        {
            if ('0' <= str[cur] && str[cur] <= '9')
            {
                v.push_back(stoi(str.substr(cur), &cnt));
                cur += cnt;
            }
            else
            {
                v.push_back(MAX_I + str[cur]);
                ++cur;
            }
        }
    }
    bool operator<(const P &R) const
    {
        size_t sz = min(v.size(), R.v.size());
        for (size_t i = 0; i < sz; i++)
        {
            if (v[i] != R.v[i])
            {
                return v[i] < R.v[i];
            }
        }
        return v.size() < R.v.size();
    }
};

int main()
{
    string str0, str;
    int n;
    cin >> n >> str0;
    P a0(str0);
    while (n--)
    {
        cin >> str;
        P cur(str);
        if (cur < a0)
        {
            cout << "-\n";
        }
        else
        {
            cout << "+\n";
        }
    }
    return 0;
}
/*

2
file10
file20
file3

11
X52Y
X
X5
X52
X52Y
X52Y6
32
ABC
XYZ
x51y
X8Y
X222

*/