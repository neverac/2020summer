#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
int N,p[MAXN],f[MAXN],cnt,K,f1[MAXN],p1[MAXN],idf[MAXN],idp[MAXN],ans[MAXN];
int check(int mid){
	int now = cnt;
	int tmp = 0;
	for (int i=mid; i>=1; i--){
		while (now > 0){
			if (f1[i] > p1[now]){
				tmp++;
				now--;
				break;
			}
			now--;
		}
	}
	return tmp == cnt;
}
multiset<int>st;
int p2[MAXN],n;
int check2(int mid,int x,int num){
//	printf("check2  %d %d %d\n",mid,x,num);
	set<int>::iterator it,it1;
	it = st.end();
	it--;
	for (int i=1; i<mid; i++) it--;
	it1 = it;
	int y = *it;
	if (y > p[x]) num++;
//	printf("it = %d\n",y);
	
	int now = n;
	it = st.end();
	it--;
	for (; ; it--){
		int t = *it;
		if (it == it1){
			if (it == st.begin()) break;
			continue;
		}
		while (now > 0){	
			if (t > p2[now]) {
				num++; now--; break;
			}
			now--;
		}
		if (now==0) break;
		if (it == st.begin()) break;
	}
//	printf("num = %d\n",num);
	return num >= cnt;
}
int main(){
	scanf("%d",&N);
	for (int i=1; i<=N; i++) scanf("%d",&p[i]),p1[i] = p[i];
	for (int i=1; i<=N; i++) scanf("%d",&f[i]),f1[i] = f[i]; 
	sort(p1+1,p1+N+1);
	sort(f1+1,f1+N+1);
	int now = N;
	for (int i=N; i>=1; i--){
		while (now > 0){
			if (f1[i] > p1[now]) {
				cnt++;
				now--;
				break;
			}
			now--;
		}
		if (now == 0) break;
	}
//	printf("debug %d\n",cnt);
	int l = 1, r = N, K = 0;
	while (l<=r){
		int mid = (l+r)>>1;
		if (check(mid)) r = mid-1, K = mid;
		else l = mid+1;
	}
//	printf("debug %d\n",K);
	
	for (int i=1; i<=N; i++) st.insert(f[i]);
	now = N; int tmp=0;
	for (int i=1; i<=N; i++){
//		printf("debug i=%d\n",i);
		
		n=0;
		for (int j=i+1; j<=N; j++) p2[++n] = p[j];
		sort(p2+1,p2+n+1);
		
		set<int>::iterator it1 = st.begin();
		int tot = 0; 
		for (; it1!=st.end(); it1++){
			if (*it1 <= p[i]) tot++;
		}
		
		int l = 1, r = st.size()-tot, t = 0;
		while (l<=r){
			int mid = (l+r)>>1;
			if (check2(mid,i,tmp)) r = mid-1,t = mid;
			else l = mid+1; 
		}
//		printf("t == %d\n",t);
		if (t==0){
			l = st.size()-tot+1; r = st.size();
			while (l<=r){
				int mid = (l+r)>>1;
				if (check2(mid,i,tmp)) r = mid-1,t = mid;
				else l = mid+1; 
			}
		}
//		printf("t == %d\n",t);
		set<int>::iterator it;
		it = st.end(); it--;
		for (int j=1; j<t; j++) it--;//
		if (*it > p[i]) tmp++;
		ans[i] = *it;
		st.erase(it);
//		puts("\n\n");
	}
//	puts("OK");
	for (int i=1; i<=N; i++) printf("%d ",ans[i]);
	return 0;
} 