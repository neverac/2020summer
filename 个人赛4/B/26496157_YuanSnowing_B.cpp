#include <bits/stdc++.h>
using namespace std;
int n,len;
string s;
int main(){
    cin >> s;
    len = s.length();
    n = s[len-1]-'0';
    if(len > 1) n += (s[len-2]-'0')*10;
    if(n%4 == 0) printf("4\n");
    else printf("0\n");
    return 0;
}