#include<bits/stdc++.h>
using namespace std;
char s[2][300];
int N,a[300];
int main(){
	int t; cin>>t;
	while (t--){
		scanf("%d",&N);
		for (int i=1; i<=N; i++){
			scanf("%d",&a[i]);
		}
		int t = 0;
		for (int i=1; i<=50; i++) s[1][i] = 'a'+t;
		for (int i=1; i<=50; i++) putchar(s[1][i]); puts("");
		int op = 0;
		for (int i=1; i<=N; i++){
			for (int j=1; j<=a[i]; j++){
				s[op][j] = s[op^1][j];
			}
			t = (t+1)%26;
			char c;
			if (s[op^1][a[i]+1] == 'z') c = 'a'; else c = s[op^1][a[i]+1]+1;
			for (int j=a[i]+1; j<=50; j++) s[op][j] =  c;
			for (int j=1; j<=50; j++) putchar(s[op][j]); puts("");
			op^=1;  
		} 
	}
	return 0;
}