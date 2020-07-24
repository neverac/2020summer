#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>
using namespace std;


int main() {
	string a;
	cin >> a;
	a = '0' + a;
	int L = a.length();
	int m = 10 * (a[L - 2] - '0') + (a[L - 1] - '0');
	int temp = pow(1, m) + pow(2, m % 4 + 4) + pow(3, m % 4 + 4) + pow(4, m % 2 + 2);
	temp %= 5;
	printf("%d\n",temp);
	return 0;
}