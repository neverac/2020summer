#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

char str0[12],str[12];

int main()
{
	int n;
	scanf("%d",&n);
	scanf("%s",str0);
	int len0=strlen(str0);
	while(n--){
		scanf("%s",str);
		int len=strlen(str);
		if(len0==len){
			int i=0;
			for(i=0;i<len;i++){
				if(str0[i]<'A'){
					if(str[i]>='A'){
						printf("+\n");
						break;
					}
					else{
						int num0=0,num=0;
						int j=i,k=i;	
						while(str0[j]<'A'&&j<len){
							num0=10*num0+str0[j]-'0';
							j++;
						}
						while(str[k]<'A'&&k<len){
							num=10*num+str[k]-'0';
							k++;
						}
						if(num0>num){
							printf("-\n");
							break;
						}
						else if(num0<num){
							printf("+\n");
							break;
						}
						else{
							i=k-1;
						}
					}
				}
				else{
					if(str[i]<'A'){
						printf("-\n");
						break;
					}
					else{
						if(str0[i]>str[i]){
							printf("-\n");
							break;
						}
						else if(str0[i]<str[i]){
							printf("+\n");
							break;
						}
					}
				}
			}
			if(i==len)printf("+\n");
		}
		else{
			int t=len0;if(len0>len)t=len;
			int i=0;
				for(i=0;i<t;i++){
				
				//
				if(i>=len0){
					printf("+\n");
					break;
				}
				else if(i>=len)
				{
					printf("-\n");
					break;
				}
				
				if(str0[i]<'A'){
					if(str[i]>='A'){
						printf("+\n");
						break;
					}
					else{
						int num0=0,num=0;
						int j=i,k=i;	
						while(str0[j]<'A'&&j<len0){
							num0=10*num0+str0[j]-'0';
							j++;
						}
						while(str[k]<'A'&&k<len){
							num=10*num+str[k]-'0';
							k++;
						}
						if(num0>num){
							printf("-\n");
							break;
						}
						else if(num0<num){
							printf("+\n");
							break;
						}
						else{
							i=k-1;
						}
					}
				}
				//
				//
				
				else{
					if(str[i]<'A'){
						printf("-\n");
						break;
					}
					else{
						if(str0[i]>str[i]){
							printf("-\n");
							break;
						}
						else if(str0[i]<str[i]){
							printf("+\n");
							break;
						}
					}
				}
				////
				////
				}
				if(i==t){
					if(len0>len){
						
						printf("-\n");
					}
					else printf("+\n");
					
				}
			
		}
	}
}