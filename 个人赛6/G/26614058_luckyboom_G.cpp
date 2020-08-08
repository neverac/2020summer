#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
long long dfs(long long  a,long long  b){
	if(a==1)return b;
	if(a==0||b==0)return 0;
	return b/a+dfs(b%a,a);
}
int main(){
	long long a,b;
	cin>>a>>b;
	if(a>b){
		cout<<a/b+dfs(a%b,b);
	}
	else cout<<dfs(a,b)<<endl;
	return 0;
}