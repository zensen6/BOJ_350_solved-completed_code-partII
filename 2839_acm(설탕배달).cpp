#include <iostream>
using namespace std;

int func(int N){
	
	int n5=(N/5);
	int n3=(N/3)+1;
	
	int N5=0;
	int N3=0;
	int i;
	for(i=n5;i>=0;i--){
		
		if((N-5*i)%3==0) break;
		
	}
	if(i<0){
		
		return -1;
	}
	else{
		
		return i+(N-5*i)/3; 
	}
	
}

int main(){
	
	
	int N;
	cin>>N;
	
	cout<<func(N)<<'\n';
	return 0;
	
	
	
}
