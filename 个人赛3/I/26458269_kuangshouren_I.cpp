#include<iostream>
using namespace std;
int h=0;int mine=0x3f3f3f3f;
char s[107];int n;
int main()
{
	cin>>n;
	scanf("%s",s+1);
	mine=0;
	for(int i=1;i<=n;++i)
	{
		if(s[i]=='+')++h;
		if(s[i]=='-')--h;
		if(h<mine)mine=h;
	}
	cout<<h-mine;
	return 0;
} 