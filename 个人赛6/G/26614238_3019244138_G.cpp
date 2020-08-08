#include <iostream>
using namespace std;

int main()
{
	long long a, b, result=0;
	cin >> a >> b;
	result=0;
	while(a)
	{
		if(a > b)
		{
			long long t = a / b;
			result+=t;
			a=a%b;
		}
		else if(a == b)
		{
			result+=a;
			a=0;
		}
		else if(a < b)
		{
			long long t = b / a;
			result+=t;
			t = b;
			b = a;
			a=t%a;
		}
	}
	cout << result << endl ;
    return 0;
}

