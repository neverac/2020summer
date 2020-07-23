#include<iostream>
#include<cstdio>
using namespace std;

char op[200];

int main() {
	int n;
	scanf("%d", &n);
	scanf("%s", op);
	int stone = 0;
	for (int i = 0; i < n; i++) {
		if (op[i] == '+') stone++;
		if (op[i] == '-') {
			stone--;
			if (stone < 0) stone = 0;
		}
	}
	printf("%d", stone);
	return 0;
	
}