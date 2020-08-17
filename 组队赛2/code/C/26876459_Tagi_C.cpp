#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int n;
int a[105];

int main()
{
	scanf("%d",&n);
	memset(a,0,sizeof(a));
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	int flag=1;
	for(int i=0;i<n-2;i++){
		for(int j=i+1;j<n-1;j++){
			for(int k=j+1;k<n;k++){
				if((a[i]-a[j])%a[k]!=0)flag=0;
				if((a[j]-a[k])%a[i]!=0)flag=0;
				if((a[i]-a[k])%a[j]!=0)flag=0;
			}
		}
	}
	if(flag)printf("yes\n");
	else printf("no\n");
	return 0;
}