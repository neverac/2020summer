 #include<bits/stdc++.h>
 using namespace std;
 inline int read(){
    int x=0,f=1; char ch=getchar();
    while(ch<'0' || ch>'9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
 }
 int N,K,a[100001];
 int main(){
 	cin>>N>>K;
 	for (int i=1; i<=N; i++){
 		a[i]=read();
 	}
 	sort(a+1,a+N+1);
 	int sum=0;
 	for (int i=1; i<=K; i++) sum += a[i];
 	printf("%d\n",sum);
	return 0;
 }
 
 