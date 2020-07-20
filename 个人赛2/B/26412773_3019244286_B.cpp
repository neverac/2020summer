#include<iostream>
using namespace std;

bool visited[65546];
bool changed[16];
int bits[16];


void bit(int number) {
	for (int i = 0; i < 16; i++) {
		int x = number >> (15 - i) & 1;
		if (x != bits[i])
		changed[i] = 1;
	}
}

int main() {
	int A, B, C, S;
	while (1) {
		cin >> A;
		if (!A)	break;
		cin >> B >> C >> S;
		memset(visited, 0, sizeof(visited));
		memset(changed, 0, sizeof(changed));
		memset(bits, 0, sizeof(bits));
		visited[S] = 1;
		int number = S;
		for (int i = 0; i < 16; i++) {
			int x = number >> (15 - i) & 1;
			bits[i] = x;
		}
		while (1) {
			number = (A * number + B) % C;
			if (visited[number]) break;
			else visited[number] = 1;
			bit(number);
		}

		for (int i = 0; i < 16; i++) {
			if (changed[i]) cout << "?";
			else cout << bits[i];
		}
		cout << endl;
	}
	
	return 0;
}