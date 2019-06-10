#include <iostream>
#include <algorithm>
using namespace std;


int arr[100000];


int main(){
	
	int N;
	int sum=0;
	cin>>N;
	for(int i=0;i<N;i++){
		
		cin>>arr[i];
		
	}
	sort(arr,arr+N);
	sum=arr[0]*N;
	for(int i=1;i<N;i++){
		
		if(arr[i]*(N-i)>sum){
			sum=arr[i]*(N-i);
		}
		
	}
	cout<<sum<<'\n';
	
}
