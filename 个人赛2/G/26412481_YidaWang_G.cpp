#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int N,K;
int a[100010];
int main(){
	scanf("%d%d",&N,&K);
	int l = 1,r = N;
	a[1] = l++;
	for (int i=1; i<K; i++) {
		if (i&1) a[i+1] = r--;
		else a[i+1]=l++;
	}
	for (int i=K+1; i<=N; i++){
		if ((K-1)&1) a[i] = r--;
		else a[i] = l++;
	}
	for (int i=1; i<=N; i++) printf("%d ",a[i]);
	return 0;
}

/*
3 2

3 1

5 2
*/