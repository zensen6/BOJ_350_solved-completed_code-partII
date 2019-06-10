#include <iostream>
using namespace std;

int main(){
	
	long long N;
	cin>>N;
	long long count=0;
	for(int i=N-1;i>=1;i--){
		
		count+=1;
		if(N%i==0) break;
		
	}
	
	cout<<count<<endl;
	return 0;
}
