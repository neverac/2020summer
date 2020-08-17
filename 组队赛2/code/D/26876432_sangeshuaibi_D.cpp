#include<bits/stdc++.h>
/*
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<iomanip>
#include<ctime> 
*/
#define ll long long
using namespace std; 
const int N=1e5 + 100;
const double eps=1e-10;
string s;
string s1="bubble";
string s2="tapioka";
int main(){
	//freopen("1.txt","r",stdin);
	bool flag=false;
	while(cin>>s){
		if(s==s1 || s==s2) continue;
		else{
			flag=true;
			cout<<s<<' ';
		}
	}
	//printf("%d",flag);
	if(!flag) printf("nothing");
	return 0;
}