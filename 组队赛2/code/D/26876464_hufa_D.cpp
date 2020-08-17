#include<string>
#include<iostream>
using namespace std;

int main() {
	string a;
	int tag = 0;
	for (int i = 0; i < 3; ++i) {
		cin >> a;
		if (a != "bubble" && a != "tapioka") {
			if (tag)
				cout << " ";
			cout << a;
			tag = 1;			
		}
	}
	if (!tag) cout << "nothing";
	cout << endl;
	return 0;
}