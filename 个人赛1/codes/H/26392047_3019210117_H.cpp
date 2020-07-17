#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n;
vector<vector<pair<int, int>>> a;
vector<int>ans;
vector<bool>b;
void sol(){
	ans.clear();
	b.resize(n,0);
	a.resize(n);
	for(int i=0;i<n-2;i++){
		int x[3];
		for(int j=0;j<3;j++){
            cin>>x[j];
            x[j]--;
        }
		a[x[0]].push_back(make_pair(x[1], x[2]));
		a[x[1]].push_back(make_pair(x[0], x[2]));
		a[x[2]].push_back(make_pair(x[0], x[1]));
	}
	for(int i=0;i<n;i++){
		if(a[i].size()==1){
			ans.push_back(i);
			if(a[a[i][0].first].size()!=2){
                swap(a[i][0].first, a[i][0].second);
            }
			ans.push_back(a[i][0].first);
			ans.push_back(a[i][0].second);
			break;
		}
	}
	for(int i:ans){
        b[i]=1;
    }
	for(int i=1;i<=n-2;i++){
		for(pair<int, int> j:a[ans[i]]){
			if(b[j.first]&&b[j.second]){
                continue;
            }
			if(b[j.first]){
				ans.push_back(j.second);
				b[j.second]=1;
				break;
			}
			if(b[j.second]){
				ans.push_back(j.first);
				b[j.first]=1;
				break;
			}
		}
	}
	for(int i:ans){
        cout<<i+1<<" ";
    }
}
int main(){
	//freopen("in.txt", "r", stdin);
	cin>>n;
	sol();
	return 0;
}