
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
#include<bitset>
#include<stdlib.h>
#include<assert.h>
#include<string>
using namespace std;
string c;
int main()
{
	int num(0),sum(0);
	int n;
	scanf("%d",&n);
	getchar();
	cin>>c;
//	cout<<c<<endl;
		for(int i=c.length()-1;i>=0;i--){
			switch(c[i]){
				case '+':
					num--;
					break;
				case '-':
					num++;
			}
			if(num<0){
				sum++;
				num++;
			}
			
		}
	
	printf("%d",sum);
	return 0;
 } 