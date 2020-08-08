#include <bits/stdc++.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--){
		int n;
		string mode = "dreamofstardreamofstardreamofstardreamofstardreamofstar";
		scanf("%d",&n);
		cout<<mode<<endl;
		for(int i = 1; i <= n; ++i){
			int x;
			scanf("%d",&x);
			mode[x]++;
			if(mode[x] > 'z') mode[x] = 'a';
			cout<<mode<<endl;
		}
	}
	return 0;
}