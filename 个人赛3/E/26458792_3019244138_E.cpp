#include <iostream>
#include <cstring>
using namespace std;
long long row[2][100010];
long long  maxnum;
long long MAX(long long  a, long long  b, long long  c){
	a = max(a,b);
	a = max(a,c);
	return a;
}
int main(){
	long long n;
	cin >> n;
	for(int i = 0 ; i < n ; i++ )
	{
		cin >> row[0][i];
	}
	for(int i = 0 ; i < n ; i++ ){
		cin >> row[1][i];
	}
	
	for(int i = n-1 ; i>= 0 ; i--){
		for(int j = 0 ; j<2 ; j++ ){
			row[j][i]=MAX(row[(j+1)%2][i+1],row[(j+1)%2][i+2],row[j][i+2])+row[j][i];
			if(row[j][i]>maxnum) maxnum=row[j][i];
			//cout << row[j][i] << endl;
		}
	}
	cout << maxnum << endl ;
	return 0;
}