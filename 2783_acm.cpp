#include<iostream>
using namespace std;

int arr[101][2];

int main(){
	
	double min = 100;
	cin>>arr[0][0]>>arr[0][1];
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		
		cin>>arr[i][0]>>arr[i][1];
		if((double)arr[i][0]/(double)arr[i][1] < min) min = (double)arr[i][0]/(double)arr[i][1];
		
	}
	
	cout<<(double)(1000)*min<<'\n';
	
	return 0;
}
