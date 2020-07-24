#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
int main()
{
    int k,n,s,p;
    cin >>k >>n >>s >>p;
    int i=1;
    while(i*s<n){
        ++i;
    }
    int ans;
    if((i*k)%p==0)
        ans = i*k/p;
    else
        ans = i*k/p +1;
    cout <<ans <<endl;
    return 0;
}
*/
/*
int main()
{
    string ch;
    cin >>ch;
    int l = ch.length();
    int x = (ch[l-2]-'0')*10 + (ch[l-1]-'0');
    if(x%2==0){
        if(x%4==0)
            cout <<4 <<endl;
        else
            cout <<0 <<endl;
    }
    else{
        cout <<0 <<endl;
    }
}
*/
/*
int t,n,a,b;

int gcd(int a,int b)
{
    if(a<b)
        swap(a,b);
    if(a%b==0)
        return b;
    return gcd(b,a%b);
}

bool judge(int i)
{
    int x = gcd(a,b);
    if(i%x==0)
        return true;
    return false;
}

int main()
{
    cin >>t;
    int cnt =-2;
    for(int j=1;j<=t;++j){
        cin >>n >>a >>b;
        for(int i=1;i<=n;++i){
            if(judge(i)){
                cnt++;
            }
        }
        if(cnt%2==0)
            //cout <<"Case #"<<j<<": Iake"<<endl;
            printf("Case #%d: Iake\n",j);
        else
            //cout <<"Case #"<<j<<": Yuwgna"<<endl;
            printf("Case #%d: Yuwgna\n",j);
        cnt = -2;
    }
    return 0;
}
*/

#include<algorithm>
#include<iostream>

using namespace std;

int gcd(int a,int b)
{
    if(a<b)
        swap(a,b);
    if(a%b==0)
        return b;
    return gcd(b,a%b);
}

int main()
{
    int t,s=1;
    cin>>t;
    while(t--)
    {
        int n,a,b;
        cin>>n>>a>>b;
        if(n/gcd(a,b)%2==0)
            cout<<"Case #"<<s++<<": Iaka"<<endl;
        else
            cout<<"Case #"<<s++<<": Yuwgna"<<endl;
    }
    return 0;
}
