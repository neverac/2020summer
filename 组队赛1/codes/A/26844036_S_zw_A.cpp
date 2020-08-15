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
#define N 10000
#define ms(x, y) memset(x, y, sizeof x)
#define INF 0x3f3f3f3f
using namespace std;

struct Item{
    bool type = false;
    int num = 0;
    char c;
    bool operator<(const Item&other){
        if(type != other.type){
            return type;
        }
        if(type){
            return num < other.num;
        }else{
            return c < other.c;
        }
    }
};

vector<Item> V[N];
int n;
string ss[N];

bool cmp(vector<Item>a,vector<Item>b){
    int a_len = a.size(), b_len = b.size();
    int len = min(a_len, b_len);
    for (int i = 0; i < len;i++){
        if(a[i] < b[i]){
            return 0;
        }else if(b[i] < a[i]){
            return 1;
        }
    }
    if(a_len < b_len){
        return 0;
    }
    return 1;
}

void handle(string s,int index){
    Item tmp;
    bool flag = false;
    for (int i = 0; i < s.size();i++){
        if(s[i] >= 'A' && s[i] <= 'z'){
            if(flag){
                V[index].push_back(tmp);
                flag = false;
            }
            tmp.type = 0;
            tmp.c = s[i];
            V[index].push_back(tmp);
        }else{
            flag = true;
            tmp.type = 1;
            tmp.num = tmp.num * 10 + s[i] - '0';
        }
    }
    if(flag){
        V[index].push_back(tmp);
    }
}

int main()
{
    // Item i;
    // i.type = false;
    // i.num = 12;
    // i.c = 'X';
    // Item j;
    // j.type = false;
    // j.num = 15;
    // j.c = 'A';
    // bool a = i < j;
    scanf("%d", &n);
    cin >> ss[0];
    for (int i = 1; i <= n;i++){
        cin >> ss[i];
    }
    for (int i = 0; i <= n;i++){
        handle(ss[i], i);
    }
    for (int i = 1; i <= n;i++){
        if(cmp(V[i],V[0])){
            printf("+\n");
        }else{
            printf("-\n");
        }
    }
    return 0;
}