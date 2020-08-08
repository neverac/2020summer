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
#define N 1000010
#define mid (l+r)/2
#define lc (x<<1)
#define rc (x<<1)|1
#define tozero(x) memset(x,0,sizeof x);
#define INF 0x3f3f3f3f
const ll mod = 1e9+7;
using namespace std;

int n,k;

int pebNum[N];
int pebPoc[N];

int main(){
    scanf("%d %d",&n,&k);
    int cnt = 0;
    for(int i=1;i<=n;i++){
        scanf("%d",&pebNum[i]);
        pebPoc[i] = ceil((double)pebNum[i]/k);
        cnt += pebPoc[i];
    }
    cnt = ceil((double)cnt/2);
    printf("%d\n",cnt);
    return 0;
}