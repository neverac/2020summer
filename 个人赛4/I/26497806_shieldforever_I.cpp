#include<bits/stdc++.h>
using namespace std;

#define base 100007
#define Mod 998244353
typedef unsigned long long ull;
ull h1[1000100], p1[1000100], h2[1000100], p2[1000100];
int o[1000100];
int len1 = 0;

char s[1000100];
char a[1000100];

ull get_hash1(int l, int r)
{
        return (h1[r] - (h1[l-1] * p1[r-l+1]) % Mod + Mod) % Mod ;
}
ull get_hash2(int l, int r)
{
        return (h2[r] - (h2[l-1] * p2[r-l+1]) % Mod + Mod) % Mod;
}

void cal_hash(int tot, int add){
    for(int i = tot + 1; i <= tot + add; i++){
        h1[i] = (h1[i-1]*base % Mod+ s[i - 1] - '0') % Mod;
        p1[i] = (p1[i-1]*base) % Mod;
    }
    return ;
}
void solve(int x){
    p2[0] = 1, h2[0] = 0;
    int len2 = strlen(a);
    for(int i = 1; i <= len2; i++){
        h2[i] = (h2[i-1]*base % Mod + a[i - 1] - '0') % Mod;
        p2[i] = p2[i-1]*base % Mod;
    }
    int len = min(len1, len2);
    for(int i = 1; i <= len; i++){
        ull h1 = get_hash1(len1 - i + 1, len1), h2 = get_hash2(1, i);
        if(h1 == h2) o[x] = i;
    }
    return ;
}


int main(){
    int n;
    cin>>n;
    scanf("%s", s);
    len1 = strlen(s);
    p1[0] = 1, h1[0] = 0;
    cal_hash(0, len1);
    for(int i = 2; i <= n; i++){
        scanf("%s", a);
        int len2 = strlen(a);
        solve(i);
        int add = 0;
        int y = len1;
        for(int j = o[i]; j < len2; j++) s[len1++] = a[j], ++add;
        cal_hash(y, add);
    }
    for(int i = 0; i < len1; i++) printf("%c", s[i]);
    return 0;
}

/*
5
simple please seaaa aab abb
*/
