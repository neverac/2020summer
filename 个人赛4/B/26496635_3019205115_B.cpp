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
