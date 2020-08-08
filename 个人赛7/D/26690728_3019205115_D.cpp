#include <iostream>
#include <bits/stdc++.h>

using namespace std;
/*
int n;
int a[105]={0};
int main()
{
    cin >>n;
    int maxa=0,maxb=0;
    int x;
    for(int i=1;i<=n;i++){
        cin >>a[i];
        if(a[i]>=maxa){
            maxa=a[i];
        }
    }
    int indx;
    bool judge=false;
    for(int i=1;i<=n;i++){
        cin >>x;
        if(x>maxa && !judge){
            indx=i;
            judge=true;
        }
        if(x>maxb){
            maxb=x;
        }
    }
    if(judge){
        cout <<n+1-indx<<endl;
        return 0;
    }
    for(int i=n;i>0;i--){
        if(a[i]>maxb){
            cout <<i<<endl;
            return 0;
        }
    }
    return 0;
}*/

long long num[10005]={0};
int factor[3]={3,5,7};
int cnt[3]={0};
int main()
{
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%lld",&num[i]);
    }
    long long sum=0;
    for(int i=0;i<N;i++){
        while(num[i]%2==0){
            num[i]/=2;
        }
        memset(cnt,0,sizeof(cnt));
        for(int j=0;j<3;j++){
           long long temp=num[i];
           while(temp%factor[j]==0){
                temp/=factor[j];
                cnt[j]++;
           }
        }
        long long temp=1;
        for(int j=0;j<=cnt[0];j++){
            for(int k=0;k<=cnt[1];k++){
                for(int l=0;l<=cnt[2];l++){
                   temp = pow(factor[0],j)*pow(factor[1],k)*pow(factor[2],l);
                   sum+=temp;
                }
            }
        }
        printf("%lld\n",sum);
        sum=0;
    }
}
