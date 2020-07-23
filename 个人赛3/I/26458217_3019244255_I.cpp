#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std; 


int main()
{
	int n;
	cin >> n;
	int i = 0;
	int cnt = 0;
	while(n --){
		char a;
		cin >> a;
		if(i == 0){
			if(a == '-')
			cnt = 0;
			else
			cnt = 1;
		}
		else
		{
			if(a == '+')
			cnt ++;
			else
			{
				if(cnt > 0)
				cnt --;
			}
			
		}
		i ++;
	}
	cout << cnt;
	return 0;
}