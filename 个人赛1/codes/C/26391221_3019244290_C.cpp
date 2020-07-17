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

vector<int> q;

void ppp(){
    int n;
    scanf("%d",&n);
        q.clear();
        vector<int> ans;
        set<int> s;
        for(int i=0;i<n;i++){
            int x;
            scanf("%d",&x);
            q.push_back(x);
            s.insert(i+1);
        }
        int m=0;
        for(int i=0;i<n;i++){
            if(q[i]>m){
                if(s.count(q[i])){
                    s.erase(q[i]);
                    ans.push_back(q[i]);
                }else{
                    printf("-1");
                    printf("\n");
                    return ;
                }
                m=q[i];
            }else{
                if(*s.begin()>m){
                   printf("-1\n");
                    return ;
                }else{
                    ans.push_back(*s.begin());
                    s.erase(s.begin());
                }
            }
        }
      for(int i=0;i<ans.size();i++){
		printf("%d ",ans[i]);
	}
	printf("\n");
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
        ppp();
	}
	return 0;
}
