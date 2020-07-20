#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int N,K;
int main(){
	scanf("%d%d",&N,&K);
	int l = 1,r = N;
	for(int i = 1;i <= K;i++){
		if(i & 1){
			printf("%d ",l);
			l++;
		}
		else{
			printf("%d ",r);
			r--;
		}
	}
	if(K & 1){
		for(int i = l;i <= r ;i++)printf("%d ",i);
	}
	else{
		for(int i = r;i >= l;i--)printf("%d ",i);
	}
	return 0;
}
/*
10 5
*/