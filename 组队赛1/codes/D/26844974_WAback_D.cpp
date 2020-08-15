#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
const int SIZEN = 4010;
const int INF = 0x3f3f3f3f;
struct Node{
    int x,y;
    Node(){;}
    Node(int x,int y){
        this->x = x;
        this->y = y;
    }
};
int f[SIZEN][SIZEN] = {0};
char g[SIZEN][SIZEN] = {0};
char s1[SIZEN];
char s2[SIZEN];
struct Seq_Auto{
    int ch[SIZEN][2];
    int S,T;
    Seq_Auto(){S = 0;T = 0;memset(ch,0,sizeof ch);}
    void build(char *s){
        int len = strlen(s+1);
        T = len + 1;
        ch[T][0] = ch[T][1] = T;
        for(int i = len;i >= 1;i--){
            ch[i][0] = ch[i+1][0];
            ch[i][1] = ch[i+1][1];
            if(s[i+1] == '0')ch[i][0] = i+1;
            else if(s[i+1] == '1')ch[i][1] = i+1;
        }
        ch[0][1] = ch[1][1];
        ch[0][0] = ch[1][0];
        if(s[1] == '1')ch[0][1] = 1;
        else ch[0][0] = 1;
    }
    void Print(){
        printf("debug : \n");
        for(int i = S;i <= T;i++){
            printf("node %d : %d %d\n",i,ch[i][0],ch[i][1]);
        }
    }
}t1,t2;
void dfs(int x,int y){
    if(f[x][y]!=INF)return;
    f[x][y] = 0;
    int t10 = t1.ch[x][0],t11 = t1.ch[x][1];
    int t20 = t2.ch[y][0],t21 = t2.ch[y][1];
    dfs(t10,t20);
    dfs(t11,t21);
    if(f[t10][t20] <= f[t11][t21]){
        f[x][y] = f[t10][t20] + 1;
        g[x][y] = 0;
    }
    else{ 
        f[x][y] = f[t11][t21] + 1;
        g[x][y] = 1;
    }
}
void print(int x,int y){
    if(x == t1.T && y == t2.T)return;
    printf("%d",g[x][y]);
    int t = g[x][y];
    print(t1.ch[x][t],t2.ch[y][t]);
}
int main(){
    scanf("%s%s",s1+1,s2+1);
    t1.build(s1);
    t2.build(s2);
    memset(f,0x3f,sizeof f);
    f[t1.T][t2.T] = 0;
    dfs(0,0);
    print(0,0);
    puts("");
    return 0;
}