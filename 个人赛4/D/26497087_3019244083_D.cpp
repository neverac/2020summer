#include <cstdio>
using namespace std;
int gcd(int a,int b)
{
	int x=a%b;
	while(x>0)
	{ 
        a=b;
        b=x;
        x=a%b;
	}
	return b;
}
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
    while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int main(){
	int T;
	scanf("%d",&T);
	for(int i = 1; i <= T; ++i){
		printf("Case #%d: ",i);
		int n,a,b;
		n= read();
		a= read();
		b= read();
		int k = gcd(a,b);
		int cnt = n/k;
		if(cnt%2) printf("Yuwgna\n");
		else printf("Iaka\n");
	}
	return 0;
} 