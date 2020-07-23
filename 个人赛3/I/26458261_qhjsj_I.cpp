#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<cstring>
#include<set>
#include<cmath>
#include<queue>
#include<sstream>
#include<algorithm>
#include<cstring>

using namespace std;

int main() {
//#define LOCAL
#ifdef LOCAL
    freopen("/Users/ttjy/Desktop/in.txt", "r", stdin);
#endif
    int m;
    cin >> m;
    int cnt = 0,res=0x7f7f7f7f;
    while (m--) {
        char c;
        cin>>c;
        if (c == '-') {
            cnt=cnt?cnt-1:0;
        } else {
            cnt++;
        }
//        res = min(res, cnt);
    }
    cout<<cnt<<endl;
    return 0;
}