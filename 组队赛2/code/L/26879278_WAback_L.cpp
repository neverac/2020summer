#include<bits/stdc++.h>
using namespace std;
#define Pa pair<int,int>
#define MP make_pair
#define LL long long
const double eps = 1e-8;
int dcmp(double x) {if(fabs(x)<eps) return 0; else return x<0? -1:1;}
struct Vector
{
    LL x,y;
    Vector(LL X=0,LL Y=0) {x=X,y=Y;}
};
typedef Vector Point;
Vector operator + (Vector A,Vector B) {return ((Vector){A.x+B.x,A.y+B.y});}
Vector operator - (Vector A,Vector B) {return ((Vector){A.x-B.x,A.y-B.y});}
bool operator < (const Vector& a,const Vector& b) {return a.x<b.x||(a.x==b.x&&a.y<b.y);}
bool operator == (const Vector& a,const Vector& b) {return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;}
LL Cross(Vector A,Vector B) {return A.x*B.y-A.y*B.x;}
LL Area2(Point A,Point B,Point C) {return Cross(B-A,C-A);}
LL PolygonArea(Point* p,int n){
    LL area=0;
    for(int i=1;i<n-1;i++)
        area+=Cross(p[i]-p[0],p[i+1]-p[0]);
    return area;
}
int ConvexHull(Point* p,int n,Point* ch){ //have no three point on one line
    sort(p,p+n);
    int k,i,m=0;
    for(i=0;i<n;i++){
        while(m>1&&dcmp(Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2]))<=0) m--;
        ch[m++]=p[i];
    }
    k=m;
    for(i=n-2;i>=0;i--){
        while(m>k&&dcmp(Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2]))<=0) m--;
        ch[m++]=p[i];
    }
    if(n>1) m--;
    return m;
}
Point p[10100],g[10100];
Point X,Y;
int vis[10100];
LL check(int x,int y){
	if (x > y) return 0;
	int l = x, r = y;
	while (r-l >= 5){
		int lmid = l+(r-l)/3;
		int rmid = r-(r-l)/3;
		LL s1 = abs(Cross(X-g[lmid], Y-g[lmid]));
		LL s2 = abs(Cross(X-g[rmid], Y-g[rmid]));
		if (s1 < s2) l = lmid;
		else r = rmid;
	}
	LL re = 0;
	for (int i=l; i<=r; i++) re = max(re, abs(Cross(X-g[i], Y-g[i])));
	return re;
}

int OK(Point a,Point b,Point p,Point q){
    return abs(Cross(b-a,p-a))<abs(Cross(b-a,q-a));
}
LL calc(Point *p,int n){
    p[n]=p[0];
    int p1,p2,i,j;
    LL ans=0,temp;
    for(i=0;i<n;i++){
        p1=(i+1)%n;
        p2=(i+2)%n;
        for(j=(i+2)%n;j!=i;j=(j+1)%n){
            while(p1!=j&&OK(p[i],p[j],p[p1],p[p1+1])) p1=(p1+1)%n;
            while(p2!=i&&OK(p[i],p[j],p[p2],p[p2+1])) p2=(p2+1)%n;
            temp=abs(Cross(p[p1]-p[i],p[j]-p[i]))+abs(Cross(p[j]-p[i],p[p2]-p[i]));
            if(temp>ans) ans=temp;
        }
    }
    return ans;
}

int main(){
	int T; cin>>T;
	while (T--){
		int N; scanf("%d",&N);
		for (int i=0; i<N; i++){
			int x,y; scanf("%d%d",&x,&y);
			p[i] = Point(x,y);
		}
		int M = ConvexHull(p,N,g);
//		printf("debug %d\n",M);
		if (M <= 2){
			puts("0");
			continue;
		}
		if (M == 4){
			LL s = PolygonArea(g,M);
			if (s & 1) printf("%lld.5\n",s/2);
			else printf("%lld\n",s/2);
			continue;
		}
		if (M == 3){
			int cnt = 0;
			for (int i=0; i<N; i++){
				vis[i] = 0;
				for (int j=0; j<3; j++) if (p[i] == g[j]) {vis[i] = 1,cnt++; break;}
			}
			LL s = PolygonArea(g,M);
			if (cnt > 3) {
				if (s & 1) printf("%lld.5\n",s/2);
				else printf("%lld\n",s/2);
				continue;
			}
			LL mn = 1e18;
			for (int i=0; i<N; i++) if (!vis[i]) {
				LL s1 = min(abs(Cross(g[0]-p[i], g[1]-p[i])), abs(Cross(g[1]-p[i],g[2]-p[i])));
				s1 = min(s1, abs(Cross(g[0]-p[i], g[2]-p[i]))); 
				mn = min(mn, s1);
			}
			s -= mn;
			if (s & 1) printf("%lld.5\n",s/2);
			else printf("%lld\n",s/2);
			continue;
		}
		LL ans = calc(g,M);
//		for (int i=0; i<M; i++){
//			for (int j=i+2; j<M; j++){
//				X = g[i]; Y = g[j];
//				LL d1 = check(i+1,j-1);
//				LL d2 = max(check(0,i-1), check(j+1,M-1));
//				ans = max(ans, d1 + d2);
//			}
//		}
		if (ans & 1) printf("%lld.5\n",ans/2);
		else printf("%lld\n",ans/2);
	}
	return 0;
}