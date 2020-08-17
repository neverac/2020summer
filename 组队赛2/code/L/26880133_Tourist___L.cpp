#include <bits/stdc++.h>
using namespace std;
const int maxn = 5000 + 10;
struct Point{
	long long x, y;
	Point(){}
	Point(long long x, long long y): x(x), y(y){}
	friend Point operator + (const Point &a, const Point &b){
		return Point(a.x + b.x, a.y + b.y);
	}
	friend Point operator - (const Point &a, const Point &b){
		return Point(a.x - b.x, a.y - b.y);
	}
	friend Point operator * (const Point &a, const double &k){
		return Point(a.x * k, a.y * k);
	}
	friend Point operator * (const double &k, const Point &a){
		return Point(a.x * k, a.y * k);
	}	
	friend double operator * (const Point &a, const Point &b){
		return a.x * b.x + a.y * b.y;
	}
	friend double operator % (const Point &a, const Point &b){
		return a.x * b.y - a.y * b.x;
	}
	friend bool operator < (const Point &a, const Point &b){
		long long t = a.y - b.y;
		return t ? t < 0 : a.x - b.x < 0;
	}
	friend bool operator == (const Point &a, const Point &b){
		return a.x == b.x && a.y == b.y;
	}
}p[maxn], s[maxn];
int n, top;
inline long long len2(Point a){
	return a.x * a.x + a.y * a.y;
}
inline bool cmp(const Point &a, const Point &b){
	long long t = (a - p[1]) % (b - p[1]);
	return t ? t > 0 : len2(a - p[1]) < len2(b - p[1]);
}
void Graham(){
	int id = 1;
	top = 0;
	for(int i = 2; i <= n; i++){
		if(p[i] < p[id]){
			id = i;
		}
	}
	swap(p[1], p[id]);
	sort(p + 2, p + n + 1, cmp);
	s[top++] = p[1];
	for(int i = 2; i <= n; i++){
		while(top >= 2 && (p[i] - s[top - 1]) % (s[top - 2] - s[top - 1]) < 0) top--;
		s[top++] = p[i];
	}
	
}
Point A, B;
double calc(Point CD){
	return (CD - A) % (B - A);
}
void xuanzhuanqiakiao(){
//	for(int i = 1; i <= n; i++){
//		cout << p[i].x << ' ' << p[i].y << endl;
//	}
//	for(int i = 0; i < top; i++){
//		cout << s[i].x << ' ' << s[i].y << endl;
//	}
	if(top < 3){
		cout << 0 << endl;
		return;
	}
	if(top == 3){
		long long mi = 1LL << 62, t;
		for(int i = 1; i <= n; i++){
			if(p[i] == s[0] || p[i] == s[1] || p[i] == s[2]) continue;
			t = (p[i] - s[0]) % (p[i] - s[1]);
			mi = min(mi, abs(t));
			t = (p[i] - s[0]) % (p[i] - s[2]);
			mi = min(mi, abs(t));
			t = (p[i] - s[1]) % (p[i] - s[2]);
			mi = min(mi, abs(t));
		}
		long long ans = (abs((s[0] - s[1]) % (s[2] - s[1])) - mi);
		if(ans & 1) cout << ans / 2 << ".5" << endl;
		else cout << ans / 2 << endl;
//		cout << 0.5 * (abs((s[0] - s[1]) % (s[2] - s[1])) - mi) << endl;
		return;
	}
	long long ans = 0, f, g;
	for(int a = 0; a < top; a++){
		A = s[a];
		int b, c, d;
		b = a + 2;
		c = a + 1;
		d = a + 3;
		f = abs(calc(s[c % top]));
		g = abs(calc(s[d % top]));
		while((b + 1) % top != a){
			B = s[b % top]; 
			while(abs(calc(s[(c + 1) % top])) - abs(calc(s[c % top])) > 0) c++;	
			while(abs(calc(s[(d + 1) % top])) - abs(calc(s[d % top])) > 0) d++;
			f = abs(calc(s[c % top]));
			g = abs(calc(s[d % top]));
			ans = max(ans, f + g);
//			printf("a %d %lf %lf\n", a, s[a % top].x, s[a % top].y);
//			printf("b %d %lf %lf\n", b, s[b % top].x, s[b % top].y);
//			printf("c %d %lf %lf\n", c, s[c % top].x, s[c % top].y);
//			printf("d %d %lf %lf\n", d, s[d % top].x, s[d % top].y);
			b++;
		}
	}
//	cout << 0.5 * ans << endl;
	if(ans & 1) cout << ans / 2 << ".5" << endl;
	else cout << ans / 2 << endl;
}
int main(){
//	freopen("tempin.txt", "r", stdin);
//	cout << fixed;
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		for(int i = 1; i <= n; i++){
			cin >> p[i].x >> p[i].y;
		}
		Graham();
		xuanzhuanqiakiao();
	}
	return 0;
}