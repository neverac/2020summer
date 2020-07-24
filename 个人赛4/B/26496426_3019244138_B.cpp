#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
using namespace std;
int main(){
    char s[1000000];
    cin >> s;
    int x = 0;
    int l = strlen(s);
    if(l >= 2)
    x = s[l-1]-'0' + (s[l-2]-'0')*10;
    else
    x=s[0]-'0';
    if(x%4 != 0)cout << 0 << endl ;
	else cout << 4 << endl ;
	return 0;
    
}