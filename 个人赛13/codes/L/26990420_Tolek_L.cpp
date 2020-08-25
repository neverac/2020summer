#include <bits/stdc++.h>
using namespace std;
const int N = 10000 + 5;
typedef long long ll;
int num[20];
string ans;
inline string get()
{
    string s = "";
    // int fl = 0;
    for (int i = 9; i >= 0; i--) {
        if (num[i] == 0) continue;
        // if (fl == 0 && i == 0) continue;
        // fl = 1;
        for (int j = 1; j <= num[i]; j++) s += i + '0';
    }
    return s;
}
inline void solve(int x, int y)
{
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
		
            if ((i & 3) != x || (j & 3) != y) continue;    
			//for(int z=0;z<10;z++)cout<<num[z]<<" ";
			//cout<<endl;
            if (num[i] <= 0 || num[j] <= 0) continue;
            if (i == j && num[i] < 2) continue;
			
            if (i == j) {
                num[i] -= 2;
                string tmp = get();
                tmp += i + '0';
                tmp += j + '0';
                if (tmp.size() < 2 || tmp[0] == '0') {
					num[i]+=2;
					continue;
				}
                if (ans.size() < tmp.size() || (ans.size() == tmp.size() && ans < tmp)) ans = tmp;
                num[i] += 2;
            } else {
                --num[i], --num[j];
                string tmp = get();
                tmp += i + '0';
                tmp += j + '0';
				//cout<<tmp<<endl;
                if (tmp.size() < 2 || tmp[0] == '0') {
					++num[i],++num[j];
					continue;
				}
                if (ans.size() < tmp.size() || (ans.size() == tmp.size() && ans < tmp)) ans = tmp;
                ++num[i], ++num[j];
            }
        }
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    while (T--) {
        for (int i = 0; i < 10; i++) scanf("%d", num + i);
        ans = "";
        solve(0, 0), solve(1, 2), solve(2, 0), solve(3, 2);
        if (ans.empty()) {
            if (num[8])
                cout << 8 << endl;
            else if (num[4])
                cout << 4 << endl;
            else if (num[0])
                cout << 0 << endl;
            else
                cout << -1 << endl;
        } else {
            if (ans[0] == '0') {
                1 / 0;
            }
            cout << ans << endl;
        }
    }
    return 0;
}