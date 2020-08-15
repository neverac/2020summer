#include<bits/stdc++.h>
#define N 4010

using namespace std;

char s1[N];
char s2[N];
int s1next[N][2];
int s2next[N][2];
int dp[N][N];
int ans[N][N];

int main()
{
    int i,j;
    int len1,len2;
    scanf("%s",s1+1);
    scanf("%s",s2+1);
	int next0,next1;
	len1=strlen(s1+1);
	next0=len1+1;next1=len1+1;
	s1next[next0][0]=s1next[next1][1]=next0;
	for(i=len1;i>=0;i--)
	{
		s1next[i][0]=next0;
		s1next[i][1]=next1;
		if(s1[i]=='0')
			next0=i;
		else
			next1=i;
	}
	len2=strlen(s2+1);
	next0=len2+1;next1=len2+1;
	s2next[next0][0]=s2next[next1][1]=next0;
	for(i=len2;i>=0;i--)
	{
		s2next[i][0]=next0;
		s2next[i][1]=next1;
		if(s2[i]=='0')
			next0=i;
		else
			next1=i;
	}
	dp[len1+1][len2+1]=-1;
	for(i=len1+1;i>=0;i--)
	{
		for(j=len2+1;j>=0;j--)
		{
			int tmp0=dp[s1next[i][0]][s2next[j][0]];
			int tmp1=dp[s1next[i][1]][s2next[j][1]];
			if(tmp0<=tmp1)
			{
				ans[i][j]=0;
				dp[i][j]=tmp0+1;
			}
			else
			{
				ans[i][j]=1;
				dp[i][j]=tmp1+1;
			}
		}
	}
	/*
	printf("=====dp========\n");
	for(i=len1;i>=0;i--)
	{
		for(j=len2;j>=0;j--)
		{
			printf("%d ",dp[i][j]);
		}
		printf("\n");
	}
	printf("=====ans=======\n");
	for(i=len1;i>=0;i--)
	{
		for(j=len2;j>=0;j--)
		{
			printf("%d ",ans[i][j]);
		}
		printf("\n");
	}*/
	i=j=0;
	for(len1=dp[0][0];len1;len1--)
	{
	//	printf("%d %d ；%d\n",i,j,ans[i][j]);
		printf("%d",ans[i][j]);
		if(ans[i][j]==0)
		{
			i=s1next[i][0];
			j=s2next[j][0];
		}
		else
		{
			i=s1next[i][1];
			j=s2next[j][1];
		}
	}
	printf("\n");
    return 0;
}