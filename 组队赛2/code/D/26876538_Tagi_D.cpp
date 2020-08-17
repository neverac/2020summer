#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

const string s1="bubble",s2="tapioka",no="nothing";

int main()
{
	string st1,st2,st3;
	int flag1(1),flag2(1),flag3(1);
	cin>>st1>>st2>>st3;
	if(st1==s1||st1==s2)flag1=0;
	if(st2==s1||st2==s2)flag2=0;
	if(st3==s1||st3==s2)flag3=0;
	if(flag1)cout<<st1<<" ";
	if(flag2)cout<<st2<<" ";
	if(flag3)cout<<st3;
	if(flag1==0&&flag2==0&&flag3==0)cout<<no;
}