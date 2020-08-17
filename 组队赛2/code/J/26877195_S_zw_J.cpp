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
#define N 2100
#define ms(x, y) memset(x, y, sizeof x)
#define INF 0x3f3f3f3f
//ll mod = 12;
using namespace std;
int n, m;
struct Data{
    bool func[N];
    Data getHe(Data D){
        Data ans;
        for (int i = 1; i <= n;i++){
            ans.func[i] = func[i] || D.func[i];
        }
        return ans;
    }
    bool full(){
        for (int i = 1; i <= n;i++){
            if(!func[i])
                return false;
        }
        return true;
    }
}datas[N];

int ans = INF;

void handle(int ma){
    int cnt = 0;
    Data tmp;
    ms(tmp.func, 0);
    for (int i = 1; i <= m;i++){
        if(ma & (1<<(i-1))){
            cnt++;
            tmp = tmp.getHe(datas[i]);
        }
    }
    if(tmp.full()){
        ans = min(ans, cnt);
    }
}

int main()
{
    int cases;
    scanf("%d", &cases);
    while (cases--)
    {
        ans = INF;
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= m;i++){
            for (int j = 1; j <= n;j++){
                int x;
                scanf("%1d", &x);
                datas[i].func[j] = x;
            }
        }

        for (int i = 1; i < (1 << m);i++){
            handle(i);
        }
        if(ans == INF){
            ans = -1;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}