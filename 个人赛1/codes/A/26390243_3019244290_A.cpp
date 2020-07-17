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

#define ull unsigned long long
using namespace std;


int a[1005];
int main(){
	int n,k,i,ans=0;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(i=1;i<=k;i++)
            ans+=a[i];
	printf("%d\n",ans);
	return 0;
}
