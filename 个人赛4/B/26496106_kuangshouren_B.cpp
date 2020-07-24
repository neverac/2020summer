#include<iostream>
#include<cstring>
using namespace std;
char s[100007];int n;
int a;
int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	if(n==1)
	{
	a=s[1]-'0';	
	}
	else
	{
		a=(s[n-1]-'0')*10+s[n]-'0';
	}
	int A=1,B=1,C=1,D=1;
	for(int i=1;i<=a;++i)
	{
		B*=2;C*=3;D*=4;
		B%=5;C%=5;D%=5;
	}
	cout<<(A+B+C+D)%5;
	return 0;
}