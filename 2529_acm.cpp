#include<iostream>
#include<string.h>
#include<cstdio>
#include<stdlib.h>
#include<cstring>
#include<memory.h>

using namespace std;

bool check[10] = {0};
long long int max0 = 0;
long long int min0 = 9876543210;
char max1[13];
char min1[13];

void go(char* str, char* arr, int n, int index){
	
	
	if(index == n+1){
		
		str[index] = '\0';
		if (stol(str) > max0) {
			max0 = atoll(str);	
			strcpy(max1, str);
			
		}
		if (stol(str) < min0) {
			min0 = atoll(str);	
			strcpy(min1, str);
			
		}
	//	for(int i=0;i<n+1;i++){
	//		cout<<str[i];
			
	//	}
	//	cout<<'\n';
		return;
		
	}
	if(index == 0){
		for(int i=0;i<=9;i++){
		
			str[index] = (char)(i+'0');
			check[i] = true;
			go(str, arr, n, index+1);
			check[i] = false;
			str[index] = 0;
		}		
		
		
	}
	else{
		
		if(arr[index-1] == '<'){
			for(int i=0;i<=9;i++){
				
				if(str[index-1]-'0' < i && !check[i]){
					str[index] = (char)(i+'0');
					check[i] = true;
					go(str, arr, n, index+1);
					check[i] = false;
					str[index] = 0;
							
				}
					
			}
				
		}
		else{
			for(int i=0;i<=9;i++){
				
				if(str[index-1]-'0' > i && !check[i]){
					str[index] = (char)(i+'0');
					check[i] = true;
					go(str, arr, n, index+1);
					check[i] = false;
					str[index] = 0;
							
				}
					
			}
				
				
		}
			
		
	}
	
	
}

int main(){
	
	int k;
	char arr[11];
	char str[13];
	char x;
	scanf("%d",&k);
	getchar();
	
	memset(str,0,sizeof(str));
	
	for(int i=0;i<k;i++){
		
		scanf("%c",&x);
		getchar();
		arr[i] = x;
		
	}

	go(str,arr,k,0);
	printf("%s\n",max1);
	printf("%s\n",min1);
	
	return 0;
}
