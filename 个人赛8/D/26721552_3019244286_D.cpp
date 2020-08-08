#include<iostream>
#include<cstring>
using namespace std;

char a[100];
int number[105];

void printchar(char* a) {
	for (int i = 0; i < 100; ++i)
		printf("%c", a[i]);
	printf("\n");
}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < 100; ++i) 
			a[i] = 'a';
		for (int i = 0; i < n; ++i) 
			scanf("%d", number + i);
		printchar(a);
		for (int i = 0; i < n; ++i) {
			for (int j = number[i]; j < 100; ++j)
				a[j] = (a[j] == 'a' ? 'b' : 'a');
			printchar(a);
		}
	}
	return 0;
}