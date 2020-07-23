#include <bits/stdc++.h>
using namespace std;
int const maxn=2e5+7;
int n,cou[4],ans[maxn];
inline int get_num(){
    char ch;
    int num=0;
    ch=getchar();
    while(ch<'0'||ch>'9'){ch=getchar();}
    while(ch>='0'&&ch<='9'){num=(num<<3)+(num<<1)+ch-'0';ch=getchar();}
    return num;
}
void work(){
	if(n==1){
		if(cou[1])printf("1\n");
		else printf("2\n");
		return ;
	}
	if(cou[1]==n){
		for(int i=1;i<n;i++)printf("1 ");
		cout<<"1"<<endl;
		return ;
	}
	if(cou[2]==n){
		for(int i=1;i<n;i++)printf("2 ");
		cout<<"2"<<endl;
		return ;
	}
	ans[1]=2;
	ans[2]=1;
	cou[1]--;cou[2]--;
	int tot=2;
	for(int i=1;i<=cou[2];i++)ans[++tot]=2;
	for(int i=1;i<=cou[1];i++)ans[++tot]=1;
	for(int i=1;i<n;i++)printf("%d ",ans[i]);
	cout<<ans[n]<<endl;
}
int main(){
	n=get_num();
	int a;
	for(int i=1;i<=n;i++){
		a=get_num();
		cou[a]++;
	}
	work();
	
	return 0;
}