#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(string a, string b)
{
    return a.size() < b.size();
}

int main()
{
    int n,m;
    set<string> cnt;
//  map<string,int> mp;
    cin>>n>>m;
    for(int i = 0; i < m;i++)
    {
        string str;
        cin>>str;
        cnt.insert(str);
    }
    set<string>::iterator it;
    vector<string> v;
    int res = 0;
    for(it=cnt.begin ();it!=cnt.end ();it++)
    {
        v.push_back(*it);
    }
    sort(v.begin(),v.end(),cmp);
    for(int i =0; i < v.size();i++)
    {
        n -= v[i].length();
        if(n >= 0)
        {
            res++;
        }
        n--;
    }
    cout<<res<<endl;
    return 0;
}
