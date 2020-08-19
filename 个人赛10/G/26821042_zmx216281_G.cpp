#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> PII;
PII p[110];
bool cmp(PII a,PII b){
    if(a.first==b.first) return a.second<b.second;
    return a.first>b.first;
}
bool cmp2(PII a,PII b){
    return a.second<b.second;
}
int main(){
    vector<PII> record;
    int n,x,m,k,pos;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> x;
        p[i].first=x;
        p[i].second=i;
    }
    sort(p+1,p+n+1,cmp);
    cin >> m;
    for(int i=1;i<=m;i++){
        cin >> k >> pos;
        record.clear();
        for(int j=1;j<=k;j++){
            record.push_back(p[j]);
        }
        sort(record.begin(),record.end(),cmp2);
        cout << record[pos-1].first<< endl;
    }
}