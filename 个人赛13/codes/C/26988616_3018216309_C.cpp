#include <bits/stdc++.h>
using namespace std;

string s;
vector<string> vec;
bool cmp(string a, string b)
{
    return a.size() < b.size();
}
int main ()
{
    int n, m;
    cin>>n>>m;

    for(int i=0; i<m; i++)
    {
        cin >> s;
        vec.push_back(s);
    }
    set<string> se(vec.begin(), vec.end());
    vec.assign(se.begin(), se.end());
    sort(vec.begin(), vec.end(), cmp);
    int cur = 0;
    for(int i=0; i<vec.size(); i++)
    {
        cur += vec[i].size()+1;
        if(cur-1>n)
        {
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<vec.size()<<endl;
}
