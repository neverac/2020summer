#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int col[60][60],room[60][60],maxans=0,cnt=0,ans;
void dfs(int i,int j){
	if(col[i][j]){
	  return;
    }
	ans++;
	col[i][j]=cnt;
	if((room[i][j]&1)==0){
        dfs(i,j-1);
    }
	if((room[i][j]&2)==0){
        dfs(i-1,j);
    }
	if((room[i][j]&4)==0){
        dfs(i,j+1);
    }
	if((room[i][j]&8)==0){
        dfs(i+1,j);
    }
}
int main(){
	int h,l;
	cin>>h>>l;
	for(int i=1;i<=h;i++){
		for(int j=1;j<=l;j++){
			cin>>room[i][j];
		}
	}
	memset(col,0,sizeof(col));
	for(int i=1;i<=h;i++){
		for(int j=1;j<=l;j++){
			if(!col[i][j]){
				cnt++;
				ans=0;
				dfs(i,j);
				maxans=max(ans,maxans);
			}
		}
	}
	cout<<cnt<<endl<<maxans<<endl;
	return 0;
}