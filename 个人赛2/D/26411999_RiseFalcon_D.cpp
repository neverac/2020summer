#include <cstdio>
#include <cmath>
#include <algorithm>
//using namespace std;
namespace uw{
	double x1,x2,x3,y1,y2,y3,a,b,c,k,d;
	double aa,bb,cc;
	void trans() {
		b=((x2*x2-x3*x3)*(y1-y2)-(x1*x1-x2*x2)*(y2-y3))/((x2*x2-x3*x3)*(x1-x2)-(x1*x1-x2*x2)*(x2-x3));
		a=(y1-y2-b*(x1-x2))/(x1*x1-x2*x2);
		c=y1-a*x1*x1-b*x1;
		k=(y3-y2)/(x3-x2);
		d=y2-k*x2;
	//	printf(">>> %lf %lf %lf\n",a,b,c);
	//	printf(">>> %lf %lf\n",k,d);
		aa=a;
		bb=b-k;
		cc=c-d;
	}
	double min(double x,double y,double z) {
		return std::min(x,std::min(y,z));
	}
	double max(double x,double y,double z) {
		return std::max(x,std::max(y,z));
	}
	
	double interal(double x) {
		return aa*x*x*x/3+bb*x*x/2+cc*x;
	}
	double funs() {
		return interal(max(x1,x2,x3))-interal(min(x1,x2,x3));
	}
}

int doing() {
	scanf("%lf%lf",&uw::x1,&uw::y1);
	scanf("%lf%lf",&uw::x2,&uw::y2);
	scanf("%lf%lf",&uw::x3,&uw::y3);
	uw::trans();
	printf("%.2lf\n",fabs(uw::funs()));
	return 0;
}
int main() {
	int t;scanf("%d",&t);
	while(t-->0)doing();
	return 0;
} 