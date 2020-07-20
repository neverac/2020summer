#include <bits/stdc++.h>
using namespace std;
struct Point{
	double x, y;
	Point(double x = 0, double y = 0): x(x), y(y){}
	friend bool operator < (const Point &a, const Point &b){
		return a.x < b.x;
	}
}p[4];
double calc2(double x, double a2, double b2, double c2 = 0){
	return a2 * x * x + b2 * x + c2;
}
double calc3(double x, double a3, double b3, double c3, double d3 = 0){
	return a3 * x * x * x + b3 * x * x + c3 * x + d3;
}
double a1, b1;
double a2, b2, c2;
int main(){
	int T;
	cin >> T;
	cout << fixed << setprecision(2);
	while(T--){
		for(int i = 1; i <= 3; i++){
			cin >> p[i].x >> p[i].y;
		}
		sort(p + 1, p + 4);
//		for(int i = 1; i <= 3; i++){
//			printf("%lf %lf\n", p[i].x, p[i].y);
//		}
		a1 = (p[3].y - p[1].y) / (p[3].x - p[1].x);
		b1 = p[1].y - a1 * p[1].x;
		a2 = (p[1].y - p[2].y) / ((p[1].x - p[2].x) * (p[1].x - p[2].x));
		b2 = -2 * a2 * p[2].x;
		c2 = a2 * p[2].x * p[2].x + p[2].y;
		
//		for(int i = 1; i <= 3; i++){
//			printf("x1 = %lf y1 = %lf cal = %lf\n", p[i].x, p[i].y, calc2(p[i].x, a2, b2, c2));
//		}
		
		double ans = fabs(calc2(p[3].x, a1 * 0.5, b1) - calc2(p[1].x, a1 * 0.5, b1)
					- calc3(p[3].x, a2 / 3, b2 * 0.5, c2) + calc3(p[1].x, a2 / 3, b2 * 0.5, c2));
		cout << ans << endl;
	}
	return 0;
}

/*
y = a * (x - p[2].x) ^ 2 + p[2].y

y = ax + b

*/

/*


*/

