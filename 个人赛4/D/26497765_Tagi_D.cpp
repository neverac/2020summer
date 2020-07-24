/**
 *　　　　　　　　┏┓　　 　┏┓
 * 　　　　　　　┏┛┗━━━━━━━┛┗━━━┓
 * 　　　　　　　┃　　　　　　　┃ 　
 * 　　　　　　　┃　　　━　　 　┃
 * 　　　　　　　┃　＞　　　＜　┃
 * 　　　　　　　┃　　　　　　　┃
 * 　　　　　　　┃...　⌒　... 　┃
 * 　　　　　　　┃　　　　　　　┃
 * 　　　　　　　┗━┓　　　┏━┛
 * 　　　　　　　　　┃　　　┃　Code is far away from bug with the animal protecting　　　　　　　　　　
 * 　　　　　　　　　┃　　　┃   神兽保佑,代码无bug
 * 　　　　　　　　　┃　　　┃　　　　　　　　　　　
 * 　　　　　　　　　┃　　　┃  　　　　　　
 * 　　　　　　　　　┃　　　┃
 * 　　　　　　　　　┃　　　┃　　　　　　　　　　　
 * 　　　　　　　　　┃　　　┗━━━┓
 * 　　　　　　　　　┃　　　　　　　┣┓
 * 　　　　　　　　　┃　　　　　　　┏┛
 * 　　　　　　　　　┗┓┓┏━┳┓┏┛
 * 　　　　　　　　　　┃┫┫　┃┫┫
 * 　　　　　　　　　　┗┻┛　┗┻┛
 */ 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<cstring>
#include<bitset>
#include<stdlib.h>
#include<assert.h>
#include<string>
#define LL long long 
#include<vector>
#include<string>
#include<stack>
using namespace std;

int gcd(LL x,LL y){
	while(y)
	{
		LL i=x%y;
		x=y;y=i;
	}
	return x;
}

int main()
{
	int t;
	scanf("%d",&t);
	int casee=0;
	while(t--)
	{
		casee++;
		int n,a,b;
		scanf("%d%d%d",&n,&a,&b);
		int t=gcd(a,b);
		int k=n/t;
		if(k%2==0){
			printf("Case #%d: Iaka\n",casee);
		}
		else{
			printf("Case #%d: Yuwgna\n",casee);
		}
	 } 
}