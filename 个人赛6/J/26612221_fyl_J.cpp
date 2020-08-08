#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-48,ch=getchar();}
	return x*f;
}	

int main(){
	int n=read(),k=read();
	int sum=0;
	for(int i=1;i<=n;i++){
		int x=read();
		sum+=(x/k)+((x%k)!=0);
	}
	printf("%d\n",sum/2+(sum%2));
	return 0;
}