#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<iomanip>
#include<cmath>
#include<algorithm>
#include<string>
#include<map>
#include<string.h>
#include<time.h>
#include<queue>
#include<stack>
using namespace std;
int main()
{  
    long long a,b;
    cin>>a>>b;
    long long sum=0;
    if(a==b)
    {
		cout<<1<<endl;
		return 0;
	}
    sum=a/b;
    long long num=0;
	a=a%b;
	while(1)
    {
		if(a == 1) 
        {
			sum += b;
			break;
		}
		if(b == 1) {
			sum += a;
			break;
		}
		sum+=b/a;
		b%=a;
		swap(a, b);
	}
	cout<<sum<<endl;
    
 
    //system("pause");
    return 0;
}

