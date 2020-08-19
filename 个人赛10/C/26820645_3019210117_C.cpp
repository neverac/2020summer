#include<iostream>
using namespace std;
string s;
int q,l,r,cnt[200005][26];
int main(){
   // freopen("in.txt","r",stdin);
    cin>>s>>q;
    for(int i=0;i<s.size();i++){
        cnt[i][s[i]-'a']++;
        if(i>0){
            for(int j=0;j<26;j++){
                cnt[i][j]+=cnt[i-1][j];
            }
        }
    }
    for(int i=0;i<q;i++){
        scanf("%d%d",&l,&r);
        if(l==r){
            printf("Yes\n");
        }else{
            l--;
            r--;
            if(s[l]!=s[r]){
                printf("Yes\n");
            }else{
                int Cnt=0;
                for(int j=0;j<26;j++){
                    int L=0,R=cnt[r][j];
                    if(l>0){
                        L=cnt[l-1][j];
                    }
                    if(R-L>0){
                        Cnt++;
                    }
                }
                if(Cnt>2){
                    printf("Yes\n");
                }else{
                    printf("No\n");
                }
            }
        }
    }
}