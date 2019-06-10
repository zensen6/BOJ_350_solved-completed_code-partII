#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[200001];

vector<int> v;

int binarysearch(int start, int end, int C, int N){
		
	int ans;
	int mid;
	while(start<=end){
		mid=(start+end)/2;
		v.clear();
		v.push_back(arr[0]);
		for(int i=1;i<N;i++){
			
			if(arr[i]-v.back()>=mid){
				
				v.push_back(arr[i]);
				
			}
			
		}
		if(v.size()>=C){
			
			ans = mid;
			start = mid+1;
			
		}
		else if(v.size()<C){
			
			end = mid-1;
			
		}
		
	}
	return ans;
}


int main(){
	
	int N,C;
	int max;
	cin>>N>>C;
	for(int i=0;i<N;i++)cin>>arr[i];
	sort(arr,arr+N);
	max = arr[N-1]-arr[0];
	
	cout<<binarysearch(1,max,C,N)<<'\n';

	return 0;
}
