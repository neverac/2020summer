#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int op[10][10], ans = 0, DD;
vector<pair<pair<int, int>, pair<int, int>>> vec;
int R(vector<pair<int, int>> vec)
{
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i].first != vec[i - 1].first) return 0;
    }
    return 1;
}
inline int RR(pair<pair<int, int>, pair<int, int>> a, pair<pair<int, int>, pair<int, int>> b)
{
    if (a.first.first != b.first.first) return 0;
    if (a.first.second > b.first.second) swap(a, b);
    return b.first.second <= a.second.second;
}
inline int CC(pair<pair<int, int>, pair<int, int>> a, pair<pair<int, int>, pair<int, int>> b)
{
    if (a.first.second != b.first.second) return 0;
    if (a.first.first > b.first.first) swap(a, b);
    return b.first.first <= a.second.first;
}
inline int RC(pair<pair<int, int>, pair<int, int>> a, pair<pair<int, int>, pair<int, int>> b)
{
    int s1 = a.first.second <= b.first.second && b.first.second <= a.second.second;
    int s2 = b.first.first <= a.first.first && a.first.first <= b.second.first;
    return s1 && s2;
}
inline int check()
{
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i].first.first < 1 || vec[i].first.first > 6) return 0;
        if (vec[i].first.second < 1 || vec[i].first.second > 6) return 0;
        if (vec[i].second.first < 1 || vec[i].second.first > 6) return 0;
        if (vec[i].second.second < 1 || vec[i].second.second > 6) return 0;
    }
    for (int i = 0; i < vec.size(); i++) {
        for (int j = i + 1; j < vec.size(); j++) {
            if (vec[i].first.first == vec[i].second.first && vec[j].first.first == vec[j].second.first) {
                if (RR(vec[i], vec[j])) {
                    // cout << i << " " << j << endl;
                    return 0;
                }
            } else if (vec[i].first.second == vec[i].second.second && vec[j].first.second == vec[j].second.second) {
                if (CC(vec[i], vec[j])) {
                    // cout << i << " " << j << endl;
                    return 0;
                }
            } else if (vec[i].first.first == vec[i].second.first) {
                if (RC(vec[i], vec[j])) {
                    // cout << i << " " << j << endl;
                    return 0;
                }
            } else {
                if (RC(vec[j], vec[i])) {
                    // cout << i << " " << j << endl;
                    return 0;
                }
            }
        }
    }
    return 1;
}
inline int check2()
{
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i].first.first == vec[i].second.first && vec[i].first.first == 3) {
            if (vec[i].second.second == 6) return 0;
        } else if (vec[i].first.second == 6) {
            if (vec[i].first.first <= 3 && vec[i].second.first >= 3) return 0;
        }
    }
    return 1;
}
void DFS(int x, int last, int to)
{
    // cout << x << " " << last << " " << to << " " << ans << endl;
    if (x > DD) return;
    if (vec.size() >= 1 && vec[0].first.first == vec[0].second.first && vec[0].first.first == 3 && vec[0].first.second == 4) {
        if (check2()) {
            ans = 1;
            return;
        }
        // for (int i = 0; i < vec.size(); i++) {
        //     cout << vec[i].first.first << " " << vec[i].first.second << " : " << vec[i].second.first << " " << vec[i].second.second << endl;
        // }
    }
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < 2; j++) {
            if (i == last && j == (to ^ 1)) continue;
            if (vec[i].first.first == vec[i].second.first) {
                vec[i].first.second += j ? 1 : -1;
                vec[i].second.second += j ? 1 : -1;
            } else {
                vec[i].first.first += j ? 1 : -1;
                vec[i].second.first += j ? 1 : -1;
            }
            //cout << vec[i].first.first << " " << vec[i].first.second << " : " << vec[i].second.first << " " << vec[i].second.second << endl;
            if (check()) DFS(x + 1, i, j);
            if (vec[i].first.first == vec[i].second.first) {
                vec[i].first.second += j ? -1 : 1;
                vec[i].second.second += j ? -1 : 1;
            } else {
                vec[i].first.first += j ? -1 : 1;
                vec[i].second.first += j ? -1 : 1;
            }
        }
    }
}
int main()
{
    // bin[0] = 1;
    // for (int i = 1; i < 12; i++) bin[i] = bin[i - 1] * 31;
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <= 6; j++) scanf("%d", &op[i][j]);
    }
    for (int z = 1; z <= 10; z++) {
        vector<pair<int, int>> tmp;
        for (int i = 1; i <= 6; i++) {
            for (int j = 1; j <= 6; j++) {
                if (op[i][j] == z) tmp.push_back({i, j});
            }
        }
        if (tmp.empty()) break;
        if (R(tmp)) {
            vec.push_back({tmp[0], tmp[tmp.size() - 1]});
        } else {
            vec.push_back({tmp[0], tmp[tmp.size() - 1]});
        }
    }
    if (vec[0].first.first == 3 && vec[0].first.second == 5) {
        printf("2");
        return 0;
    }
    for (int i = 0; i <= 7; i++) {
        // cout << i << endl;
        DD = i, DFS(0, -1, 0);
        if (ans) {
            printf("%d", i + 3);
            return 0;
        }
    }
    printf("-1");
    return 0;
}
