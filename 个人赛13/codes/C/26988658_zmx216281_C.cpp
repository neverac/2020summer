#include <iostream>
#include <vector>
#include <math.h>
#include <iomanip>
#include <algorithm>
#include <set>
using namespace std;
bool cmp(string s1, string s2) {
    return s1.size() < s2.size();
}
int main(){
    int m,n;
    int ans = 0;
    set<string> ss;
    vector<string> ll;
    string s;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        cin >> s;
        ss.insert(s);
    }
    for (auto i : ss) ll.push_back(i);
    sort(ll.begin(),ll.end(),cmp);
    for (int i=0;i<ll.size();i++) {
        n-=ll[i].size();
        if(n>=0)ans++;
        n-=1;
    }
    cout << ans << endl;
    return 0;
}