#include<iostream>
using namespace std;

long long d[91];

int main(){

	d[0] =0;
	d[1] = d[2] = 1;
	
	int n;
	cin>>n;
	for(int i=3;i<=n;i++){
		
		d[i] = d[i-1]+d[i-2];
		
	}
	cout<<d[n]<<'\n';
	
	
	return 0;
}
