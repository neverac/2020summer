 #include<stdio.h>
#include<string.h>
#include<string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#define ll long long 
#define N 200010
#define mid ((l+r)>>1)
#define lc (x<<1)
#define rc (x<<1)|1
#define tozero(x) memset(x,0,sizeof x);
#define INF 0x3f3f3f3f
const ll mod = 1e9+7;
using namespace std;

int n;
int a[N];
int l[N], r[N];

int main()
{
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        l[i]=1;
    }
    for(int i=1;i<=n;i++){
        r[i]=1;
    }
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
    }
    int Max=1;
    for(int i=n-1;i>=1;i--)
    {
        if(a[i]<a[i+1]){
            r[i]=r[i+1]+1;
        }
        Max = max(Max,r[i]);
    }
    for(int i=2;i<=n;i++)
    {
        if(a[i]>a[i-1]){
            l[i]=l[i-1]+1;
        }
        Max=max(Max,l[i]);
    }
    for(int i=1;i<=n-2;i++)
    {
        if(a[i]<a[i+2]){
            Max=max(Max,l[i]+r[i+2]);
        }
    }
    printf("%d\n", Max);
    return 0;
}