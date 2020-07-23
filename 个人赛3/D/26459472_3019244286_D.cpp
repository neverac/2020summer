#include<iostream>
using namespace std;

bool prim[400000];
int number[200000];

void is_prim() {
	prim[0] = prim[1] = 1;
	for (int i = 2; i <= 400000; i++) {
		if(!prim[i])
			for (int j = 2; j * i < 400000; j++) {
				prim[j * i] = 1;
			}
	}
}

int main() {
	is_prim();
	int n;
	scanf("%d", &n);
	int count1 = 0, count2 = 0, temp;
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		if (temp == 1)count1++;
		else count2++;
	}
	int sum = 0,index = 0;
	while (count1 || count2) {
		if (sum >= index)
			while (prim[++index]);
		if (sum) printf(" ");
		if (count2 && index - sum >= 2) {
			sum += 2;
			printf("2");
			count2--;
		}
		else if (count1){
			sum += 1;
			printf("1");
			count1--;
		}
		else {
			sum += 2;
			printf("2");
			count2--;
		}
	}
	printf("\n");
	return 0;
}