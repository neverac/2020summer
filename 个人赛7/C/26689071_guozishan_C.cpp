#include <iostream>

using namespace std;
int rec1[105];
int rec2[105];


int main()
{
    int N;
    cin>>N;
    for(int i = 1; i <= N; i++)
    {
        cin>>rec1[i];
    }
    for(int i = 1; i <= N; i++)
    {
        cin>>rec2[i];
    }
    int i =1 ,j =1;
    while(i <= N && j <= N)
    {
        if(rec1[i] > rec2[j])
        {
            j++;
        }else{
            i++;
        }
    }
    //cout<<i << " "<<j<<endl;
    if(i >=N)
    {
        cout<<N-j+1<<endl;
    }else
    {
        cout<<N-i+1<<endl;
    }
    return 0;
}
