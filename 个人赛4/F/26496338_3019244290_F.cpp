#include <iostream>
#include <stdio.h>
#include<cmath>
#include<cctype>
#include<cstdio>
#include <algorithm>
#include <string.h>
#include <string>
#include<math.h>
#include<map>
#include<unordered_map>
#define Maxn 100005
#define ll long long
using namespace std;


int main()
{
    int k,n,s,p,num1,num2,sum;
    scanf("%d%d%d%d",&k,&n,&s,&p);
    num1=n%s==0? n/s:(n/s+1);
    num2=num1*k;
    sum=num2%p==0? num2/p:(num2/p+1);
    printf("%d\n",sum);
    return 0;
}
