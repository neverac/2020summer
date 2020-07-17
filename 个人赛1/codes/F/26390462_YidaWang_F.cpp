 #include<bits/stdc++.h>
 using namespace std;
 inline int read(){
    int x=0,f=1; char ch=getchar();
    while(ch<'0' || ch>'9') {if(ch=='-') f=-1; ch=getchar();}
    while(ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
 }
 int N,Q,a[100010],b,c,cnt[100010];
 #define LL long long
 int main(){
 	N=read();
 	LL sum = 0;
 	for (int i=1; i<=N; i++) a[i]=read(),cnt[a[i]]++,sum+=a[i];
 	Q=read();
 	while (Q--){
 		b=read(),c=read();
 		sum -= 1LL*cnt[b]*b;
 		sum += 1LL*cnt[b]*c;
 		cnt[c] += cnt[b];
 		cnt[b] = 0;
 		printf("%lld\n",sum);
 	}
 	return 0;
 }
 
 
 /*
4
1 2 3 4
3
1 2
3 4
2 4
 */