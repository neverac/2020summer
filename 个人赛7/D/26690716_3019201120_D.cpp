#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll cnt1;
ll cnt2;
ll cnt3;
const int N=1e5;
ll q[N];
int main()
{	
	int n;
    cin>>n;
	while(n--)
	{
		ll x;
		ll ans=0;
        cnt1=0;
        cnt2=0;
        cnt3=0;
		cin>>x;
		while(x%3==0)
		{
			
			x/=3;
            cnt1++;
            //cout<<"round1"<<endl;
		}
		while(x%5==0)
		{
			cnt2++;
			x/=5;
            //cout<<"round2"<<endl;
        }
		while(x%7==0)
		{
			cnt3++;
			x/=7;
            
 //           cout<<"round3"<<endl;
		}
        //cout<<cnt1<<' '<<cnt2<<' '<<cnt3<<endl;
		//ans=cnt1+cnt2+cnt3+cnt1*cnt2*cnt3+cnt1*cnt2+cnt2*cnt3+cnt1*cnt3+1;
        
        for(int i=0;i<=cnt1;i++)
            for(int j=0;j<=cnt2;j++)
                for(int k=0;k<=cnt3;k++)
                    ans=ans+pow(3,i)*pow(5,j)*pow(7,k);
        
        
		cout<<ans<<endl;
	}


    system("pause");
}