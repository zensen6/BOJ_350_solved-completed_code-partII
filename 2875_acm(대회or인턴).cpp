#include<iostream>
using namespace std;

int main(){
	
	int N,M,K;
	cin>>N>>M>>K;
	int min = (N/2<=M) ? N/2:M;
	int surp = (N+M)-(3*min);
	if(surp>=K) cout<<min<<'\n';
	else{
		
		while(surp<K){
			
			surp+=3;
			min-=1;
			
		}
		cout<<min<<'\n';
		
	}
	
	return 0;
}
