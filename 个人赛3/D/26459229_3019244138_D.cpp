#include <iostream>
using namespace std;
int main(){
	long long n, one=0, two=0;
	int num;
	cin >> n;
	
	while(n--){
		scanf("%d",&num);
		switch(num){
			case 1: one++; break;
			case 2: two++; break;
		}
	}
	//cout << one << two << endl ;
	if(two){
		printf("2 "); two--;
		if(one){
			printf("1 "); one--;
		}
	}
	else {
		while(one){
			printf("1 ");
			//cout << "done" << endl ;
			one--;
		}
	}
	while(two--)
		printf("2 ");
	
	while(one--)
		printf("1 ");
	return 0;
}