#include <iostream>
#include <stdio.h>
#include<cmath>
#include<cctype>
#include<cstdio>
#include <algorithm>
#include <string.h>
#include<math.h>
#include<map>
#include<bits/stdc++.h>
#include<unordered_map>
#define Maxn 100005
#define ll long long
using namespace std;

ll sum;
int num[Maxn];
int a[Maxn];
int main(){
	int n,q,b,c;
	scanf("%d",&n);
	sum=0;
	for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
        num[a[i]]++;//a[i]出现的次数
	}
    scanf("%d",&q);
	for(int i=1;i<=q;i++){
        scanf("%d%d",&b,&c);
        sum+=(c-b)*num[b];
        num[c]+=num[b];
        num[b]=0;
        printf("%lld\n",sum);
	}
	return 0;
}
