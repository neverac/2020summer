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
#define ll long long
#define N 1010
#define mid ((l + r) >> 1)
#define lc (rt << 1)
#define rc ((rt << 1) | 1)
#define tree_len (r - l + 1)
#define left_len (mid - l + 1)
#define right_len (r - mid)
#define tozero(x) memset(x, 0, sizeof x);
#define INF 0x3f3f3f3f
const ll mod = 1e5 + 7;
using namespace std;

int n, m;

struct Pos{
    int x, y;
    int getDis(const Pos &p){
        return abs(x - p.x) + abs(y - p.y) + 1;
    }
    Pos(int x, int y):x(x), y(y){};
    Pos(){}
};

Pos school[N * N / 2];
Pos company[N * N / 2];

int cnt_school, cnt_company;

int Map[N][N];

int main(){
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= m;j++){
            scanf("%1d", &Map[i][j]);
            if(Map[i][j] == 1){
                cnt_school++;
                school[cnt_school] = Pos(i, j);
            }
            if(Map[i][j] == 2){
                cnt_company++;
                company[cnt_company] = Pos(i, j);
            }
        }
    }
    int dis = INF;
    for (int i = 1; i <= cnt_school;i++){
        for (int j = 1; j <= cnt_company;j++){
            if(school[i].getDis(company[j]) < dis){
                dis = school[i].getDis(company[j]);
                if(dis == 2){
                    printf("2\n");
                    return 0;
                }
            }
        }
    }
    printf("%d\n", dis);
    return 0;
}