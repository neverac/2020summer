#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
struct Point{
	long long int x, y;
	Point() {}
	Point(long long int xx, long long int yy) :x(xx), y(yy) {}
	Point operator + (const Point& k1) const { return Point(k1.x + x, k1.y + y); }
	Point operator - (const Point& k1) const { return Point(x - k1.x, y - k1.y); }
	Point operator * (long long int k1) const { return Point(x * k1, y * k1); }
	Point operator / (long long int k1) const { return Point(x / k1, y / k1); }
	bool operator < (const Point& b) const {
		return (x < b.x) || (x == b.x && y < b.y);
	}
	bool operator ==(const Point& b) const {
		return (x == b.x) && (y == b.y);
	}
	long long int abs() { return x * x + y * y; }
	long long int dis(Point k1) { return ((*this) - k1).abs(); }
    void read(){
        scanf("%lld%lld",&x,&y);
    }
    void print(){
        printf("(%lld,%lld)\n",x,y);
    }
};
 
long long int cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }	//叉积
long long int dot(Point a, Point b) { return a.x * b.x + a.y * b.y; }	//点积
long long int area(Point a, Point b, Point c) { return abs(cross(a - b, a - c)); }
 
vector<Point> getTub(vector<Point>A){
	int n=A.size();
    vector<Point>ans(2*n);
	sort(A.begin(),A.end());
    int now=-1;
	for(int i=0;i<n;i++){
		while(now>0&&cross(ans[now]-ans[now-1],A[i]-ans[now-1])<0){
            now--;
        }
        ans[++now]=A[i];
	}
	int pre=now;
	for(int i=n-2;i>=0;i--){
		while(now>pre&&cross(ans[now]-ans[now-1],A[i]-ans[now-1])<0){
            now--;
        }
        ans[++now]=A[i];
	}
	ans.resize(now);
	return ans;
}

long long int xzqq(vector<Point>&p){
	long long int ans=0;
	for(int i=0;i<p.size();i++){
		int p1=(i+1)%p.size(),p2=(p1+2)%p.size();
		for(int j=(p1+1)%p.size();(j+1)%p.size()!=i;j=(j+1)%p.size()){
			while((p1+1)%p.size()!=j&&area(p[i],p[(p1+1)%p.size()],p[j])>area(p[i],p[p1],p[j])){
				p1=(p1+1)%p.size();
            }
			if(p2==j){
                p2=(p2+1)%p.size();
            }
			while((p2+1)%p.size()!=i&&area(p[j],p[(p2+1)%p.size()],p[i])>area(p[j],p[p2],p[i])){
				p2=(p2+1)%p.size();
            }
			ans=max(ans,area(p[i],p[p1],p[j])+area(p[j],p[p2],p[i]));
		}
	}
	return ans;
}
void cal3tub(long long int &maxs,int n,vector<Point>tub,vector<Point>p){
    long long int tems=area(tub[0],tub[1],tub[2]);
    for(int i=0;i<n;i++){
        if(p[i]==tub[0]||p[i]==tub[1]||p[i]==tub[2]){
            continue;
        }
        long long int mins=min(area(p[i],tub[1],tub[2]),min(area(tub[0],p[i],tub[2]),area(tub[0],tub[1],p[i])));
        maxs=max(maxs,tems-mins);
    }
}
int main() {
    //freopen("in.txt","r",stdin);
    int t,n;
    vector<Point>p,tub;
    scanf("%d",&t);
	while(t--){
        scanf("%d",&n);
		p.resize(n);
		for(int i=0;i<n;i++){
            p[i].read();
        }
		tub=getTub(p);
		long long int maxs=0;
		if(tub.size()<3){
            maxs=0;
		}else if(tub.size()==3){
            cal3tub(maxs,n,tub,p);
		}else{
            maxs=xzqq(tub);
        }
        if(maxs&1){
            printf("%lld.5\n",maxs/2);
        }else{
            printf("%lld\n",maxs/2);
        }
	}
    return 0;
}