#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 100

using namespace std;

int n;
struct item
{
	bool isnum;
	int num;
}s0[N],si[N];
int cnt0,cnt1;
char s[100];
bool cmp()
{
	int i;
	for(i=0;i<cnt0;i++)
	{
		if(si[i].isnum != s0[i].isnum)
			return si[i].isnum;
		if(si[i].num!=s0[i].num)
			return si[i].num<s0[i].num;
	}
	return false;
}
void make(item* s0,int &cnt0)
{
	int i;
	int tmp;
	bool numing=false;
	for(i=0;s[i];i++)
	{
		if(s[i]>='0' &&s[i]<='9')
		{
			if(numing)
			{
				tmp=tmp*10+s[i]-'0';
			}
			else
			{
				tmp=s[i]-'0';
				numing=true;
			}
		}
		else
		{
			if(numing)
			{
				s0[cnt0].num=tmp;
				s0[cnt0].isnum=true;
				cnt0++;
			}
			numing=false;
			s0[cnt0].isnum=false;
			s0[cnt0].num=s[i];
			cnt0++;
		}
	}
	if(numing)
	{
		s0[cnt0].num=tmp;
		s0[cnt0].isnum=true;
		cnt0++;
	}
//	printf("=========\n");
//	for(i=0;i<cnt0;i++)
	{
//		printf("%d %d\n",s0[i].isnum,s0[i].num);
	}
//	printf("=========\n");
}
int main()
{
	int i;
	bool numing;
	scanf("%d",&n);
	scanf("%s",s);
	int tmp;
	make(s0,cnt0);
	for(i=1;i<=n;i++)
	{
		scanf("%s",s);
		cnt1=0;
		make(si,cnt1);
		si[cnt1].isnum=true;
		si[cnt1].num=-1;
		if(cmp())
			printf("-\n");
		else
			printf("+\n");
	}
	return 0;
}