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
#define N 500
#define ms(x, y) memset(x, y, sizeof x)
#define INF 0x3f3f3f3f
using namespace std;

struct Element{
    int num,index;

} eles[N];

bool cmp1(Element e1,Element e2){
    if(e1.num == e2.num)
        return e1.index > e2.index;
    return e1.num < e2.num;
}

bool cmp2(Element e1,Element e2){
    return e1.index < e2.index;
}

int n,m;

vector<Element> ans;

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n;i++){
        scanf("%d", &eles[i].num);
        eles[i].index = i;
    }
    sort(eles + 1, eles + 1 + n,cmp1);
    scanf("%d", &m);
    for (int i = 1; i <= m;i++){
        ans.clear();
        int k, pos;
        scanf("%d %d", &k, &pos);
        for (int i = n - k + 1; i <= n;i++){
            ans.push_back(eles[i]);
        }
        sort(ans.begin(), ans.end(), cmp2);
        printf("%d\n", ans[pos - 1].num);
    }
    return 0;
}