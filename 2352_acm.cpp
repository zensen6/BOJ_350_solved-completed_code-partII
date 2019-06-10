#include<iostream>
#include<algorithm>
using namespace std;

int d[40001];
int arr[40001];

int main(){
	
	int n;
	int m=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		
		cin>>arr[i];
		d[i] =1;
	}
	d[1] =1;
	for(int i=2;i<=n;i++){
		
		for(int j=i-1;j>=1;j--){
			
			if(arr[i]>arr[j]){
				
				d[i] = max(d[i],d[j]+1);
				
			}
			
		}
		
		
	}
	for(int i=1;i<=n;i++){
		
		if(d[i]>m) m=d[i];
		
	}
	cout<<m<<'\n';
	
	
	return 0;
}
