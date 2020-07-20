 #include<bits/stdc++.h>
 using namespace std;
 #define LL long long
 int main(){
	int T; cin>>T;
	int cas = 0;
	while (T--){
		cas++;
		char s[30];
		scanf("%s",s+1);
		int n = strlen(s+1);
		LL x = 0, y = 0,mx = -(1LL<<61);
		for (int i=1; i<n-5; i++){
			x = x*10 + s[i]-'0';
			y = 0;
			for (int j=i+1; j<n-4; j++) y = y*10+s[j]-'0';
			//printf("debug %lld %lld\n",x,y);
			mx = max(mx,x+y);
		}
		int A = s[n-3]-'0', B = s[n-2]-'0', C = (s[n-1]-'0')*10+s[n]-'0';
		x=0;
		for (int i=1; i<n-4; i++){
			x = x*10+s[i]-'0';
			y = 0;
			for (int j=i+1; j<n-3; j++) y = y*10+s[j]-'0';
		//	printf("debug %lld %lld %d %d %d\n",x,y,A,B,C);
			mx = max(mx,x+y-A*B/C);
		}
		A = s[n-2]-'0'; B = s[n-1]-'0'; C = s[n]-'0';
		x=0;
		for (int i=1; i<n-3; i++){
			x = x*10+s[i]-'0';
			y = 0;
			for (int j=i+1; j<n-2; j++) y = y*10+s[j]-'0';
		//	printf("debug %lld %lld %d %d %d\n",x,y,A,B,C);
			mx = max(mx,x+y-A*B/C);
		}	
		printf("Case #%d: %lld\n",cas,mx);
	}	
}

/*
1
12345
*/