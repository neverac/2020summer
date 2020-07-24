#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n;
    char s[100005];
    scanf("%s",s);
    n = strlen(s);
    int a = s[n-1];
    int b = s[n-2];
    int key = a+b*10;
    if(!(key%4))cout<<4<<endl;
    else cout<<0<<endl;
    return 0;
}