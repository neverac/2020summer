#include <stdio.h>
#include <string.h>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector> 
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <set>
#define ll long long
#define N 610000
#define ms(x, y) memset(x, y, sizeof x)
#define INF 0x3f3f3f3f
using namespace std;


bool cmp(string s1, string s2)
{
    return s1.size() < s2.size();
}

vector<string> V;

int main ()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        string ss;
        cin >> ss;
        V.push_back(ss);
    }
    set<string> S(V.begin(), V.end());
    V.assign(S.begin(), S.end());
    sort(V.begin(), V.end(), cmp);
    int len = -1;
    for(int i=0; i<V.size(); i++)
    {
        len += V[i].size()+1;
        if(len > n)
        {
            printf("%d\n", i);
            return 0;
        }
    }
    printf("%d\n", V.size());
    
    return 0;
}