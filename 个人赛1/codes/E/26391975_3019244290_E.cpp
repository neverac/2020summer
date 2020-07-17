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

char s[15];
int main(){
	ll n;
	int m=0;

	scanf("%lld",&n);
	while(n){
        s[m++]=(n-1)%26+'a';
        n--;
        n/=26;
	}
	for(int i=m-1;i>=0;i--)
        putchar(s[i]);
    printf("\n");
	return 0;
}
