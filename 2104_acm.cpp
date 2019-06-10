#include<iostream>

using namespace std;

int arr[100000];
long long d[100000];


long long go(int N){
	
	d[0] = arr[0];
	long long min=d[0];
	long long sum=d[0];
	long long max=-1;
	for(int i=1;i<N;i++){
			
		if(arr[i]>min){
			
			if(arr[i]*arr[i]>=d[i-1]+min*arr[i]){
				d[i]=arr[i]*arr[i];
				min=arr[i];
				sum=arr[i];	
			} 
			else{
				d[i] = d[i-1]+min*arr[i];	
				sum+=arr[i];
			} 
			
		}
		else{
			
			sum+=arr[i];
			d[i] =sum*arr[i];
			min = arr[i];
			
		}
		
	}
	for(int i=0;i<N;i++){
		
		if(d[i]>max) max=d[i];
		
	}
	return max;
	
}

int main(){
	
	int N;
	cin>>N;	
	for(int i=0;i<N;i++) cin>>arr[i];
	cout<<go(N)<<'\n';
	
	return 0;
}
