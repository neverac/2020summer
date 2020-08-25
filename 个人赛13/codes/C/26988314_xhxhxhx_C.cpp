#include <set>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    set<string> q;
    string str;
    for (int i = 0; i < m; i++)
    {
        cin >> str;
        q.insert(str);
    }
    vector<int> v;
    for (const auto &i : q)
    {
        v.push_back(int(i.size()));
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for (const auto &i : v)
    {
        if (n > i)
        {
            n -= i + 1;
            ++ans;
        }
        else if (n == i)
        {
            ++ans;
            break;
        }
        else
        {
            break;
        }
    }
    cout << ans << endl;
    return 0;
}