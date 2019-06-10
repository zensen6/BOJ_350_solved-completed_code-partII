#include<iostream>
#include<memory.h>
#include<algorithm>

using namespace std;


int arr[100001];
int nw[100001];

int main(){
	
	memset(arr,0,sizeof(arr));
	memset(nw,0,sizeof(nw));
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>arr[i];
	int sum = 0;
	
	for(int i=0;i<n;i++){
		
		if(i<k-1){
			
			sum+=arr[i];	

		} 
		else if(i==k-1){
			
			sum+=arr[i];
			nw[i] = sum;
		
		}
		else{
			
			sum+=arr[i];
			sum-=arr[i-k];
			nw[i] = sum;
			
		}
		
	}
	sort(nw+k-1,nw+n);
	reverse(nw+k-1,nw+n);
	
	cout<<nw[k-1]<<'\n';
	
	return 0;
}
