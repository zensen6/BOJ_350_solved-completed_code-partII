#include <iostream>
#include <algorithm>
using namespace std;

int arr[9];
int arr1[7];
int main(){
	
	int sum=0;

	for(int i=0;i<9;i++){
		
		cin>>arr[i];
		sum+=arr[i];
		
	}
	sort(arr,arr+9);
	int i=0;
	int j=0;
	for(i=0;i<8;i++){
		for(j=i+1;j<9;j++){
			
			if(sum-arr[i]-arr[j]==100){
				
				for(int k=0;k<9;k++){
					
					if(k!=i && k!=j){
						cout<<arr[k]<<'\n';
					}
					
				}
				break;
					
			}
				
			
			
		}
		
		
	}
	

/*
	int cnt=0;
	for(int k=0;k<9;k++){
		
		
		if(k==i || k==j){
			continue;	
			
		}
		else{
			
			arr1[cnt++]=arr[k];
		}
	}*/
	
	return 0;
}
