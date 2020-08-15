#include <bits/stdc++.h>
using namespace std;
const int N = 10000 + 5;
typedef long long ll;
int r, s, p;
vector<int> vec;
int main()
{
    scanf("%d%d%d", &r, &s, &p);
    int bx = r + 1, by = s + 1;
    for (int i = 1; i <= p; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        if (y > s) ++y;
        vec.push_back(abs(x - bx) + abs(y - by));
    }
    sort(vec.begin(), vec.end());
    for (int i = 1; i < vec.size(); i++) {
        if (vec[i] <= vec[i - 1]) vec[i] = vec[i - 1] + 1;
    }
    printf("%d", vec[vec.size() - 1]);
    return 0;
}
// 5 2 7
// 1 1
// 1 2
// 1 3
// 2 3
// 2 4
// 4 4
// 5 2