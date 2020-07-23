#include<iostream>
#include<cstdio>
using namespace std;

char maps[60][60];

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int r, c;
		scanf("%d%d", &r, &c);
		for (int i = 0; i < r; i++) {
			getchar();
			for (int j = 0; j < c; j++) {
				scanf("%c", &maps[i][j]);
			}
		}

		bool hasA = 0;
		bool hasP = 0;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (maps[i][j] == 'A')
					hasA = 1;
				else hasP = 1;
			}
		}
		if (!hasA) {
			printf("MORTAL\n");
			continue;
		}
		if (!hasP) {
			printf("0\n");
			continue;
		}

		bool step1 = 0;
		bool step2 = 0;
		bool step3 = 0;
		for (int i = 0; i < r; i++) {
			bool line = 1;
			for (int j = 0; j < c; j++) {
				if(maps[i][j]=='P')
					line = 0;
			}
			if (line) {
				if (!i || i == r - 1) {
					step1 = 1;
					break;
				}
				else step2 = 1;
			}
		}

		for (int i = 0; i < c; i++) {
			bool line = 1;
			for (int j = 0; j < r; j++) {
				if(maps[j][i] == 'P')
					line = 0;
			}
			if (line) {
				if (!i || i == c - 1) {
					step1 = 1;
					break;
				}
				else step2 = 1;
			}
		}

		for (int j = 0; j < c; j++) {
			if (maps[0][j] == 'A' || maps[r - 1][j] == 'A') {
				step3 = 1;
				break;
			}
		}

		for (int i = 0; i < r; i++) {
			if (maps[i][0] == 'A' || maps[i][c-1] == 'A') {
				step3 = 1;
				break;
			}
		}

		if (maps[0][0] == 'A' || maps[0][c - 1] == 'A' || maps[r - 1][0] == 'A' || maps[r - 1][c - 1] == 'A')
			step2 = 1;

		if (step1) printf("1\n");
		else if (step2) printf("2\n");
		else if (step3) printf("3\n");
		else printf("4\n");
	}
	return 0;
}