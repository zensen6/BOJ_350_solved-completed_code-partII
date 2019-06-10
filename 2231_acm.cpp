#include<iostream>
using namespace std;

int arr[100001];

int sum(int n){
	
	int s= 0;
	while(n>0){
		
		s+=n%10;
		n/=10;
		
	}
	return s;
	
}



int main(){
	
	int n;
	bool yes= false;
	cin>>n;
	for(int i=1;i<=1000000;i++){
		
		arr[i] = sum(i);
		
	}
	for(int i=1;i<=n;i++){
		
		if(arr[i]==n){
			
			yes=true;
			cout<<i<<'\n';
			return 0;			
		}
		
	}
	
	if(!yes) cout<<0<<'\n';
	return 0;

}
