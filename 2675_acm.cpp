#include<iostream>

using namespace std;

int main(){
	
	int t;
	cin>>t;
	string x;
	int n;
	while(t--){
		cin>>n>>x;
		string str = "";
		for(auto a:x){
			
			for(int i=0;i<n;i++) str+=a;
			
		}
		cout<<str<<'\n';
		
	}
	
	
	return 0;
}
