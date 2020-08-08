 #include<stdio.h>
#include<string.h>
#include<string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#define ll long long 
#define N 50010
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1)|1
#define tozero(x) memset(x,0,sizeof x);
#define INF 0x3f3f3f3f
const ll mod = 1e9+7;
using namespace std;

int n;
int a[N];
char s[N];
int main(){
    int cases;
    scanf("%d", &cases);
    while (cases--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
        if(a[1] != 0){
            for (int i = 1; i <= a[1];i++){
                s[i] = 'a';
            }
            s[a[1]+1] = '\0';
        }else{
            s[1] = 'a', s[2] = '\0';
        }
        printf("%s\n", s+1);
        for (int i = 1; i < n;i++){
            char c = s[a[i] + 1];
            if(c == '\0'){
                c = 'a';
            }else{
                c = (c - 'a' + 1) % 26 + 'a';
            }
            s[a[i] + 1] = c;
            for (int j = a[i] + 2; j <= a[i + 1];j++){
                s[j] = 'a';
            }
            s[max(a[i]+1,max(a[i + 1] + 1,2))] = '\0';
            printf("%s\n", s + 1);
        }
        if(a[n] != 0){
            s[a[n] + 1] = '\0';
        }else{
            char c = s[1];
            c = (c - 'a' + 1) % 26 + 'a';
            s[1] = c;
            s[2] = '\0';
        }

        printf("%s\n", s + 1);
    }
    
    return 0;
}