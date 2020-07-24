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

using namespace std;
const int Maxn=1e6+10;
int net[Maxn];


void getnext(string s){
    int l=s.size();
    net[0]=net[1]=0;
    int j=0;
    for(int i=2;i<=l;i++){
        while(j&&s[i-1]!=s[j])
            j=net[j];
        if(s[i-1]==s[j])
            j++;
        net[i]=j;
    }
}


int main()
{
    ios::sync_with_stdio(0);
	cin.tie(0);

    int n;

    string s1;
    cin>>n>>s1;

    for(int i=1;i<n;i++){
        string s2;
        cin>>s2;
        int l=s2.size();
        net[0]=net[1]=0;
        int j=0;
        for(int i=2;i<=l;i++){
        while(j&&s2[i-1]!=s2[j])
            j=net[j];
        if(s2[i-1]==s2[j])
            j++;
        net[i]=j;
        }
        j=0;
        int l1=s1.size();
        for(int i=max(1,l1-l+1);i<=l1;i++){
            while(j&&s1[i-1]!=s2[j])
                j=net[j];
            if(s1[i-1]==s2[j])
                j++;
        }
        for(int i=j;i<l;i++)
            s1+=s2[i];

    }
    cout<<s1<<endl;
    return 0;
}
