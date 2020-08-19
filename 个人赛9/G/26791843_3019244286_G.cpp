#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;

struct Tshirt {
	int tag,money,front,back,index;
	bool operator<(const Tshirt a) const{
		return money > a.money;
	}
}shirt[200004];

priority_queue<Tshirt> color[3];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &shirt[i].money);
	for (int i = 0; i < n; ++i)
		scanf("%d", &shirt[i].front);
	for (int i = 0; i < n; ++i)
		scanf("%d", &shirt[i].back);
	for (int i = 0; i < 200000; ++i)
		shirt[i].index = i;
	for (int i = 0; i < n; ++i) {
		color[shirt[i].front].push(shirt[i]);
		if(shirt[i].front!=shirt[i].back)
		color[shirt[i].back].push(shirt[i]);
	}
	int m,temp;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		if (i) printf(" ");
		scanf("%d", &temp);
		while (!color[temp].empty() && shirt[color[temp].top().index].tag) color[temp].pop();
		if (color[temp].empty()) 
			printf("-1");
		else {
			printf("%d", color[temp].top().money);
			shirt[color[temp].top().index].tag = 1;
		}
	}
	printf("\n");
	return 0;
}