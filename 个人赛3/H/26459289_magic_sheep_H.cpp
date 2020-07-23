#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int T,n,m;

char s[100][100];
bool judge0()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]!='A') return false;
		}
	}
	return true;
}

bool judge1()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='A') return false;
		}
	}
	return true;
}

bool judge2()
{
	int cnt = 0;
	for(int i=1;i<=n;i++) if(s[i][1]=='A') cnt++;
	if(cnt==n) return true;
	cnt =0 ;
	for(int i=1;i<=n;i++) if(s[i][m]=='A') cnt++;
	if(cnt==n) return true; 
	 cnt = 0;
	for(int i=1;i<=m;i++) if(s[1][i]=='A') cnt++;
	if(cnt==m) return true;
	cnt =0 ;
	for(int i=1;i<=m;i++) if(s[n][i]=='A') cnt++;
	if(cnt==m) return true; 
	return false;
}

bool judge3()
{
	if(s[1][1]=='A') return true;
	if(s[1][m]=='A') return true;
	if(s[n][1]=='A') return true;
	if(s[n][m]=='A') return true;
	for(int i=1;i<=n;i++)
	{
		int cnt =0;
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='A') cnt++;
		}
		if(cnt==m) return true;
	}
	for(int j=1;j<=m;j++)
	{
		int cnt =0 ;
		for(int i=1;i<=n;i++)
		{
			if(s[i][j]=='A') cnt++;
		}
		if(cnt==n) return true;
	}
	return false;
}
bool judge4()
{
	int cnt = 0;
	for(int i=1;i<=n;i++) if(s[i][1]=='A') cnt++;
	if(cnt) return true;
	cnt =0 ;
	for(int i=1;i<=n;i++) if(s[i][m]=='A') cnt++;
	if(cnt) return true; 
	cnt = 0;
	for(int i=1;i<=m;i++) if(s[1][i]=='A') cnt++;
	if(cnt) return true;
	cnt =0 ;
	for(int i=1;i<=m;i++) if(s[n][i]=='A') cnt++;
	if(cnt) return true; 
	return false;
}



int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s[i]+1);			
		}
		if(judge0())
		{
			cout<<"0"<<endl;
		}
		else if(judge1())
		{
			cout<<"MORTAL"<<endl;
		}
		else if(judge2())
		{
			cout<<1<<endl;
		}
		else if(judge3())
		{
			cout<<2<<endl;
		}
		else  if(judge4())
		{
			cout<<3<<endl;
		}
		else cout<<4<<endl;
	}
	return 0;
}
/*
4
7 8
AAPAAAAA
PPPPAAAA
PPPPAAAA
APAAPPPP
APAPPAPP
AAAAPPAP
AAAAPPAA
6 5
AAAAA
AAAAA
AAPAA
AAPAP
AAAPP
AAAPP
4 4
PPPP
PPPP
PPPP
PPPP
3 4
PPPP
PAAP
PPPP
 */