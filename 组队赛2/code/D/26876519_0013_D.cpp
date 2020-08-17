#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[40];
int main()
{
	int tot=0;
	while(~scanf("%s",s+1))
	{
		int l=strlen(s+1);
		if((l==6&&s[1]=='b'&&s[2]=='u'&&s[3]=='b'&&s[4]=='b'&&s[5]=='l'&&s[6]=='e')||(l==7&&s[1]=='t'&&s[2]=='a'&&s[3]=='p'&&s[4]=='i'&&s[5]=='o'&&s[6]=='k'&&s[7]=='a'))
		continue;
		else
		{++tot;
		printf("%s ",s+1);
		}
	}
	if(tot==0)
	cout<<"nothing";
	return 0;
}
