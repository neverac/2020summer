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
#include<set>
#include<unordered_map>
#define Maxn 100000007
#define ll long long

using namespace std;

vector<string> v;
set<string> se;

bool cmp(string x,string y){
    return x.size()<y.size();
}

int main() {
    int n,m;
    int num=0;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        string s;
        cin>>s;
        se.insert(s);
    }
    for(auto x:se)
        v.push_back(x);
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<v.size();i++){
        n-=v[i].size();
        if(n>=0)
            num++;
        n--;
    }
    cout<<num<<endl;
    return 0;
}
