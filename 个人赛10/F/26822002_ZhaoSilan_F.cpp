#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int trie[3000005][2],cnt ;
void insert(long long int a){//建trie树
int root = 0;
for(int i = 29;i>=0;i--){
    int c = (a>>i)&1ll;
    if(!trie[root][c]) trie[root][c] = ++cnt; // 如果没有，就添加结点
     root = trie[root][c];
   }
}

ll solve(int cur,int k){
  if(k == -1) return 0;//已经搜索到最底层的位数了
  if(trie[cur][0] == 0){
      return solve(trie[cur][1],k-1);
  }
   else if(trie[cur][1] == 0){
   return solve(trie[cur][0],k-1);
   }
   else{
     return (1<<k)+min(solve(trie[cur][0],k-1),solve(trie[cur][1],k-1));
   }
 }

int main()
{
     int n;
     scanf("%d",&n);
     for(int i = 0;i<n;i++)
     {
         long long int a;
         scanf("%lld",&a);
         insert(a);
     }
     cout<<solve(0,29);
     return 0;
 }
    
