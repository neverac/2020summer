#include <iostream>
#include <string>
using namespace std;

string a;
int lit;
int ans;

int main()
{
    int n;
    cin>>n;
    cin>>a;
    for(int i=0;i<n;i++)
    {
        if(a[i]=='-') lit-=1;
        else lit+=1;
        ans=min(ans,lit);
    }
    int an2=-ans;
    for(int i=0;i<n;i++)
    {
        if(a[i]=='-') an2--;
        else an2++;
    }
    cout<<an2<<endl;
}
