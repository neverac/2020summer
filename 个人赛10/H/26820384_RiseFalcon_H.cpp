#include <bits/stdc++.h>
using namespace std;
auto Int=[](const string&s)->int{
	int l=s.length();
	int ans=0;
	for(int i=0;i<l;++i) {
		ans=ans*10+s[i]-'0'; 
	}return ans;
};
auto input=[]()->string{
	string s;
	getline(cin,s);
	return s;
};
auto split=[](const string&s,char mid=' ')->vector<string> {
	int last=0;
	int l=s.length();
	vector<string>ans;
	for(int i=0;i<l;++i) {
		if(s[i]==mid&&last<i-1) {
			ans.push_back(s.substr(last,i-last));
			last=i+1;
		}
	}if(last<l)ans.push_back(s.substr(last,l-last));
	return ans;
};
template<typename T,typename V>
vector<T> mapF(function<T(const V&)>each,const vector<V>&ary) {
	vector<T>ans;
	for(auto it:ary) {
		ans.push_back(each(it));
	}return ans;
}
template<typename T>
vector<T> take(const vector<T>&v,int l,int r) {
	if(r==-1)return vector<T>(v.begin()+l,v.end());
	else return vector<T>(v.begin()+l,v.begin()+r);
}
template<typename T>
vector<T> operator + (vector<T>a,const vector<T>&b) {
	a.insert(a.end(),b.begin(),b.end());
	return a;
}
template<typename T>
vector<T> List(initializer_list<T> a) {
	return vector<T>(a.begin(),a.end());
}
struct Range {
	int st,ed,sep;
	struct iterator {
		int x;
		iterator(int v) {x=v;}
		bool operator !=(const iterator&v) {return x!=v.x;}
		int operator*() const {return x;}
		const iterator& operator ++ () {++x;return *this;}
	};
	Range(int n) {st=0;ed=n;sep=1;}
	Range(int l,int r) {st=l;ed=r;sep=1;}
	Range(int l,int r,int sp) {st=l;ed=r;sep=sp;}
	iterator begin() const {return iterator(st);} 
	iterator end() const {return iterator(ed);}
}; 
#define append push_back
























const int MAXN=1E6+10;
int a[MAXN];
int main() {
	int n;cin>>n;
	for(int i=1;i<=n;++i) {
		cin>>a[i];
	}
	int ans=0,sm=0;
	for(auto i :Range(1,n+1)) {
		a[i]+=a[i-1]; 
	}ans=360;
	for(auto i: Range(1,n+1)) {
		for(auto j:Range(0,i)) {
			ans=min(ans,abs((360-a[i]+a[j])-(a[i]-a[j])));
		}
	}cout<<ans<<endl;
	return 0;
}




















