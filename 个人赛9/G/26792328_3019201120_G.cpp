#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
//hope mm gl & hf
//hope TianJiang live longer

const int N=2e5+10;
int c[N];
typedef struct node{
    int a;
    int b;
    int c;
}z;
z az[N];
typedef priority_queue<int ,vector<int>,greater<int>> q;
q a11;
q a12;
q a13;
q a23;
q a22;
q a33;
int mon[3];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++) 
        cin>>az[i].a;
    for(int i=0;i<n;i++)
        cin>>az[i].b;
    for(int i=0;i<n;i++)
        cin>>az[i].c;
    //for(int i=0;i<n;i++) cout<<az[i].a<<az[i].b<<az[i].c<<endl;
    for(int i=0;i<n;i++)
    {
        //cout<<i<<' ';
        if(az[i].b==1&&az[i].c==1) 
        {
            a11.push(az[i].a);
            //cout<<a11.top()<<endl;
        }
        else if((az[i].b==1&&az[i].c==2)||(az[i].b==2&&az[i].c==1)) 
        {
            a12.push(az[i].a);
            //cout<<a12.top()<<endl;
        }
        else if((az[i].b==1&&az[i].c==3)||(az[i].b==3&&az[i].c==1))
        {
            a13.push(az[i].a);
            //a13.pop();
            //cout<<a13.top()<<endl;
        } 
        else if((az[i].b==2&&az[i].c==2))
        {
            a22.push(az[i].a);
            //cout<<a22.top()<<endl;
        } 
        else if((az[i].b==3&&az[i].c==2)||(az[i].b==2&&az[i].c==3))
        {
            //cout<<a23.top()<<endl;
            a23.push(az[i].a);
        } 
        else if(az[i].b==3&&az[i].c==3)
        {
            a33.push(az[i].a);
            //cout<<a33.top()<<endl;
        } 
        //cout<<a11.top()<<endl;
    }
    
    int m;
    cin>>m;
    for(int i=0;i<m;i++) cin>>c[i];
    int x;
    for(int i=0;i<m;i++)
    {
        if(c[i]==1)
        {
            if(a11.empty()) mon[0]=0;
            else mon[0]=a11.top();
            if(a12.empty()) mon[1]=0;
            else mon[1]=a12.top();
            if(a13.empty()) mon[2]=0;
            else mon[2]=a13.top();
            
            sort(mon,mon+3);
            if(mon[0]||mon[1]||mon[2])
            {
                if(mon[0]) 
                {
                    x=mon[0];
                }
                else if(mon[1]){
                    x=mon[1];
                }
                else {
                    x=mon[2];
                }
                cout<<x<<' ';
            }
            else 
                cout<<-1<<' ';
            if(!a11.empty()&&x==a11.top()) a11.pop();
            else if(!a12.empty()&&x==a12.top()) a12.pop();
            else if(!a13.empty()&&x==a13.top()) a13.pop();
        }
        
        else if(c[i]==2)
        {
            if(a22.empty()) mon[0]=0;
            else mon[0]=a22.top();
            if(a12.empty()) mon[1]=0;
            else mon[1]=a12.top();
            if(a23.empty()) mon[2]=0;
            else mon[2]=a23.top();
            sort(mon,mon+3);
            if(mon[0]||mon[1]||mon[2])
            {
                if(mon[0]) 
                {
                    x=mon[0];
                }
                else if(mon[1]){
                    x=mon[1];
                }
                else {
                    x=mon[2];
                }
                cout<<x<<' ';
            }
            else 
                cout<<-1<<' ';
            if(!a22.empty()&&x==a22.top()) a22.pop();
            else if(!a12.empty()&&x==a12.top()) a12.pop();
            else if(!a23.empty()&&x==a23.top()) a23.pop();
        }
        else if(c[i]==3)
        {
            if(a33.empty()) mon[0]=0;
            else mon[0]=a33.top();
            if(a13.empty()) mon[1]=0;
            else mon[1]=a13.top();
            if(a23.empty()) mon[2]=0;
            else mon[2]=a23.top();
            sort(mon,mon+3);
            if(mon[0]||mon[1]||mon[2])
            {
                if(mon[0]) 
                {
                    x=mon[0];
                }
                else if(mon[1]){
                    x=mon[1];
                }
                else {
                    x=mon[2];
                }
                cout<<x<<' ';
            }
            else 
                cout<<-1<<' ';
            if(!a33.empty()&&x==a33.top()) a33.pop();
            else if(!a13.empty()&&x==a13.top()) a13.pop();
            else if(!a23.empty()&&x==a23.top()) a23.pop();
        }
        
    }
    cout<<endl;
    
    
}