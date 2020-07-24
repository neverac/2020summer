#include<stdio.h>
#include<string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iostream>
#define N 10005
#define INF 0x3f3f3f3f
using namespace std;

int k,n,s,p;

int main()
{
    scanf("%d %d %d %d",&k,&n,&s,&p);
    int ans = ceil((ceil((double)n/s) * k )/p);
    printf("%d\n",ans);
    return 0;
}
 