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
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define ll long long

using namespace std;


int main()
{
    int n,t;
    scanf("%d",&t);
    while(t--){
    scanf("%d",&n);

    string s(200,'a');

    cout<<s<<endl;
    for(int i=1;i<=n;i++){
        int a;
        scanf("%d",&a);
        s[a]=s[a]=='a'?'b':'a';
        cout<<s<<endl;
    }
    }
    return 0;

}
