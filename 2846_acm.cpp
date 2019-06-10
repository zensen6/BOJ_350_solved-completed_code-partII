#include<iostream>
#include<vector>
using namespace std;

int main(){
	
	int N,x;
	cin>>N;
	int d=0;
	int max = 0;
	vector<int> v;
	while(N--){
		cin>>x;
		v.push_back(x);
		
	}
	for(int i=0;i<v.size()-1;i++){
		
		if(v[i+1]-v[i]>0) d+=(v[i+1]-v[i]);
		if(d>max) max=d;
		if(v[i+1]-v[i]<=0) d=0;
		
	}
	
	cout<<max<<'\n';
	return 0;
}
