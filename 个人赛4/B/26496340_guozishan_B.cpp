#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char rec[100010];
int main()
{

        scanf("%s",rec);
        int temp = 0;
        for(int i =0; i < strlen(rec);i++){
            temp = (temp*10+rec[i]-'0')%4;
        }
        if(temp%4 == 0){
            cout<<4<<endl;
        }else{
            cout<<0<<endl;
        }
    return 0;
}
