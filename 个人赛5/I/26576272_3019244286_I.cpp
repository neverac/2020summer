#include<iostream>
#include<cstdio>
using namespace std;

int odd[300000];
int even[300000];

int main() {
	int t;
	scanf("%d", &t);
	getchar();
	while (t--) {
		char c;
		int oddcnt = 0, evencnt = 0;
		while (scanf("%c", &c) && c != '\n') {
			int temp = c - '0';
			if (temp & 1) odd[oddcnt++] = temp;
			else even[evencnt++] = temp;
		}
		int oddtag = 0, eventag = 0;
		while (oddtag != oddcnt || eventag != evencnt) {
			while (oddtag == oddcnt && eventag != evencnt) {
				printf("%d", even[eventag++]);
			}
			while (eventag == evencnt && oddtag != oddcnt) {
				printf("%d", odd[oddtag++]);
			}
			while (oddtag != oddcnt && eventag != evencnt) {
				if (even[eventag] > odd[oddtag])
					printf("%d", odd[oddtag++]);
				else
					printf("%d", even[eventag++]);
			}
		}
		printf("\n");
	}
	return 0;
}