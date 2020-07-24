#include<stdio.h>
#include<string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iostream>
#define N 10005
#define INF 0x3f3f3f3f
using namespace std;

string s;

int main()
{
    while (cin>>s)
    {
        int tmp = 0;
        for(int i=0;i<s.size();i++){
            tmp = (tmp*10 + s[i]-'0')%4;
        }
        if(tmp == 0){
            printf("4\n");
        }else{
            printf("0\n");
        }
    }
    
    return 0;
}
 