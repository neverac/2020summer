#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define N 100100

using namespace std;

int main()
{
    double k,n,s,p;
    scanf("%lf%lf%lf%lf",&k,&n,&s,&p);
    printf("%d\n",int(ceil(ceil(n/s)*k/p)));
    return 0;
}
