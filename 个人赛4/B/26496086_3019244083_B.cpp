#include <bits/stdc++.h> 
using namespace std;
char c[110000];
int main()
{
    scanf("%s",c);
    int k;
    int n=strlen(c);
    if(n==1) k=c[n-1]-'0';
	else
	{ 
       int k1=c[n-2]-'0';
       int k2=c[n-1]-'0';
       k=k1*10+k2;
    }  
    if(k%4==0) cout<<4;
	if(k%4==1) cout<<0;
	if(k%4==2) cout<<0;
	if(k%4==3) cout<<0;
    return 0;
}