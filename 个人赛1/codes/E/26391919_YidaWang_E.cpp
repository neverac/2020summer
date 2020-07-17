 #include<bits/stdc++.h>
 using namespace std;
 inline int read(){
    int x=0,f=1; char ch=getchar();
    while(ch<'0' || ch>'9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
 }
 #define LL long long
 #define MAXN 100010
 LL N;
 int a[100010];
 int main(){
	cin>>N;
	int cnt = 0;
	LL base = 26;
	while (N){
		a[++cnt] = N%26;
		N /= 26;
	}
	//if (cnt>1 && a[cnt]==1) cnt--,a[cnt]+=26;
	for (int i=1; i<cnt; i++){
		if (a[i] <= 0){
			a[i] += 26; 
			a[i+1] --;
		}
	}
	while (a[cnt]<=0) cnt--;
	/*
	for (int i=cnt; i; i--){
		//putchar(a[i] + 'a'-1);
		printf("%d\n",a[i]);
	}
	*/
	for (int i=cnt; i; i--){
		putchar(a[i] + 'a'-1);
	}
	puts("");
 	return 0;
 }
 
 
 /*
2

27

123456789

1

26

702

475253
 */