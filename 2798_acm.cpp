#include<iostream>
#include<vector>

using namespace std;

int arr[100];

int main(){
	
	int min = 300000;
	int sum = 0;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>arr[i];
	
	for(int i=0;i<n-2;i++){
		for(int j=i+1;j<n-1;j++){
			for(int k=j+1;k<n;k++){
				
				sum=arr[i]+arr[j]+arr[k];	
				if(sum<=m && (m-sum)<min) min = m-sum;
				
			}
			
		}
		
	}
	cout<<m-min<<'\n';
	
	return 0;
}
