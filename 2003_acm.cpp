#include<iostream>
using namespace std;

int arr[10000];

int main(){
	
	int n,m;
	cin>>n>>m;
	int count = 0;
	int sum= 0;
	for(int i=0;i<n;i++){
		
		cin>>arr[i];
		
	}
	int i,j;
	sum = arr[i];
	for(i=j=0;i<n&&j<n;){
		
		if(sum>m){
			
			sum-=arr[i];
			i+=1;
			
		}
		else{
			if(sum==m){
				
				count++;
				
			}
			
			j++;
			sum+=arr[j];
			
		}
								 // sum<m : j++,sum+=arr[j]
			                     // sum>m : sum-=arr[i], i+=1
			        			 // sum==m : j++ , sum+=arr[j]
		
	}
	cout<<count<<'\n';
	
	
	
	return 0;
}
