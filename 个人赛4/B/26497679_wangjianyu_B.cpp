#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
#define N 100100

using namespace std;


char a[N];
int main()
{
	scanf("%s",a);
	int l=strlen(a);
	int x;
	if(l >= 2)
        x = a[l-1]-'0' + (a[l-2]-'0')*10;
	else
        x = a[0] - '0';
	if(x%4 != 0)
        printf("0");
	else
        printf("4");
	return 0;
}
