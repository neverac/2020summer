#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
typedef int int_;
#define int long long
#define maxn 1000010
const int inf=1e9+7;
inline int read(){
	int ret=0,ff=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') ff=-ff;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ret=ret*10+ch-'0';
		ch=getchar();
	}
	return ret*ff;
}
int a[60][60];
int vis[60][60];
int dfs(int x,int y){
	int ret=0;
	vis[x][y]=1;
//	printf("%d %d %d %d\n",x,y,a[x][y],a[x][y]&1);
	if((a[x][y]&1)==0){	
		if(vis[x][y-1]==0){
			ret+=dfs(x,y-1);
		}
	}
	if((a[x][y]&2)==0){	
		if(vis[x-1][y]==0){
			ret+=dfs(x-1,y);
		}
	}
	if((a[x][y]&4)==0){	
		if(vis[x][y+1]==0){
			ret+=dfs(x,y+1);
		}
	}
	if((a[x][y]&8)==0){	
		if(vis[x+1][y]==0){
			ret+=dfs(x+1,y);
		}
	}
	return ret+1;
}
struct Point{
	double x,y;
}p1,p2,p3,p[5];
bool cmp(Point t1,Point t2){
	return t1.x<t2.x;
}
int_ main(){
	int T=read();
	while(T--){
		scanf("%lf%lf%lf%lf%lf%lf",&p[1].x,&p[1].y,&p[2].x,&p[2].y,&p[3].x,&p[3].y);
		sort(p+1,p+1+3,cmp);
		p1=p[2],p2=p[1],p3=p[3];
		double b=(p2.x*p2.x-p3.x*p3.x)*(p1.y-p2.y)-(p1.x*p1.x-p2.x*p2.x)*(p2.y-p3.y);
		b/=(p2.x*p2.x-p3.x*p3.x)*(p1.x-p2.x)-(p1.x*p1.x-p2.x*p2.x)*(p2.x-p3.x);
		double a=p1.y-p2.y-b*(p1.x-p2.x);
		a/=p1.x*p1.x-p2.x*p2.x;
		double c=p1.y-a*p1.x*p1.x-b*p1.x;
	//	printf("%lf %lf %lf\n",a,b,c);
		a=a/3.0;b=0.5*b;
		double x=p2.x;
		double qwq=a*x*x*x+b*x*x+c*x;
		x=p3.x;
		double qaq=a*x*x*x+b*x*x+c*x;
		double S1=qaq-qwq;
		double k=(p3.y-p2.y)/(p3.x-p2.x);
	//	printf("k=%lf\n",k);
		double B=p3.y-k*p3.x;
		x=p2.x;
		qwq=k*0.5*x*x+B*x;
		x=p3.x;
		qaq=k*0.5*x*x+B*x;
		double S2=qaq-qwq;
		printf("%.2lf\n",S1-S2); 
	}
	return 0;
}
/*
1
12
1 1 2 4 8 16 32 64 128 256 512 1024
*/