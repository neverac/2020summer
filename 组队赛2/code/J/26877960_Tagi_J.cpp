#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<bitset>
#include<set>
using namespace std;

bitset<505> a[25];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++){
			getchar();
			char ch;
			for(int j=0;j<n;j++){
				scanf("%c",&ch);
				if(ch=='1')a[i][j]=1;
				else a[i][j]=0;
			}
		}
		int an=999,ans=0;
		int flag=1;
		for(int i=0;i<(1<<m);i++){
			bitset<505> tt;
			ans=0;
			for(int j=0;j<m;j++){
				if(i&(1<<j)){
					tt=tt|a[j];
					ans++;
				}
				flag=1;
				for(int k=0;k<n;k++){
					if(tt[k]==0)
					{
						flag=0;
						break;
					}
				}
				if(flag!=0){
					an=min(an,ans);
				}
			}
		}
		if(an>15)printf("-1\n");
		else printf("%d\n",an);
	}
	return 0;
}