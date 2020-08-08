#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cstdio>
#define ll long long
using namespace std;
const int int_inf = 0x3f3f3f3f;
inline int readint()
{
    int ret = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return ret;
}
inline ll readll()
{
    ll ret = 0;
    char c = getchar();
    while (c < '0' || c > '9')
        c = getchar();
    while (c >= '0' && c <= '9')
    {
        ret = ret * 10 + c - '0';
        c = getchar();
    }
    return ret;
}
char s[200100];
int cnt[10];
vector<int>link[10];
int main(){
    int T = readint();
    while(T--){
        int ans = int_inf;
        scanf("%s", s + 1);
        int len = strlen(s + 1);
        for(int i = 0; i <= 9; i++){
            cnt[i] = 0;
            link[i].clear();
        }
        for(int i = 1; i <= len; i++){
            int cur = s[i] - '0';
            ++cnt[cur];
            link[cur].push_back(i);
        }
        for(int i = 0; i <= 9; i++)
        for(int j = i + 1; j <= 9; j++){
            int tcnt = 0;
            int len1 = link[i].size();
            int len2 = link[j].size();
            if(len1 == 0)continue;
            if(len2 == 0)continue;
            int cur1 = 0, cur2 = 0;
            int last = -1;
            while(cur1 < len1 && cur2 < len2){
                int pos1 = link[i][cur1];
                int pos2 = link[j][cur2];
                if(pos1 < pos2){
                    if(i != last){
                        ++tcnt;
                        last = i;
                    }
                    ++cur1;
                }else{
                    if(j != last){
                        ++tcnt;
                        last = j;
                    }
                    ++cur2;
                }
            }
            if(cur1 < len1){
                if(i != last){
                    ++tcnt;
                    last = i;
                }
            }
            if(cur2 < len2){
                if(j != last){
                    ++tcnt;
                    last = j;
                }
            }
            if(tcnt % 2) --tcnt;
            ans = min(ans, len - tcnt);
        }
        for(int i = 0; i <= 9; i++)
            ans = min(ans, len - cnt[i]);
        printf("%d\n", ans);
    }
    return 0;
}