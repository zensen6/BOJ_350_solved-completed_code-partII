#include<iostream>
#include<cstring>

using namespace std;

bool good(char* str, int n){
	
	int i,len;
	
	for(len = 1; len<=n/2; len++){
		for( i=n-1; i>n-len-1;i--){
			
			if(str[i]!=str[i-len]){
				
				break;	
			}		
				
		}
		if(i == n-len-1) return false;
		
	}
	return true;
	
}


bool go(char* str, int index, int n){
	
	if(index == n){
		
		return true;
		
	}
	
	for(int i=1;i<=3;i++){
		
		str[index] = char(i+'0');
		if(good(str,index+1)){
			
			if(go(str,index+1,n)){
				
				return true;
				
			}
			
		}

	}
	return false;
	
}


int main(){
	
	char str[82];
	int n;
	cin>>n;
	go(str,0,n);
	for(int i=0;i<n;i++){
		
		cout<<str[i];
	}

	return 0;
}
