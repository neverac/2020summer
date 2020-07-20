#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main() {
	int i,j,k,t,m,n;
	int cnt;
	while(scanf("%d%d",&n,&k)!=EOF) {
		int l = 1;
		int r = n;

		if(k%2==0) {
			if(k==2) {
				cout<<1<<' ';
				for(i=r; i>=2; i--)
					cout<<i<<' ';
			} else {
				cnt = 0;
				int tp = (k%2==0)?k/2:(k-1)/2;
				for(; cnt<tp; l++,r--) {
					cout<<l<<' ';
					cout<<r<<' ';
					cnt++;
				}
				for(; l<=r; r--)
					cout<<r<<' ';
			}
		} else {
			cnt = 0;
			if(k==1) {
				for(i=1; i<=n; i++) {
					cout<<i<<' ';
				}
			} else {
				cnt =0;
				for(; cnt<(k-1)/2; l++,r--) {
					cout<<l<<' ';
					cout<<r<<' ';
					cnt++;
				}
				for(; l<=r; l++) {
					cout<<l<<' ';
				}
			}
		}
		cout<<endl;
	}
	return 0;
}
