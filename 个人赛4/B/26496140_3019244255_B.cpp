#include <iostream>
#include <cstring>
using namespace std; 
const int n = 1e5 + 10;
char a[n];
int main()
{
	cin >> a;
	int l = strlen(a);
	int x ;
	if(l >= 2)x = a[l-1]-'0' + (a[l-2]-'0')*10;
	else x = a[0] - '0';
	if(x%4 != 0)printf("0");
	else printf("4");
	return 0;
}
