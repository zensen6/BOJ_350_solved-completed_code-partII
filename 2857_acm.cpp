#include<iostream>
#include<vector>
using namespace std;

int main(){
	
	vector<int> v;
	string x;
	for(int i=0;i<5;i++){
		
		cin>>x;
		bool yes = false;
		for(int j=0;j<x.length()-2;j++){
			
			if(x[j]=='F' && x[j+1] =='B' && x[j+2] == 'I')yes=true;
			
		}
		if(yes) v.push_back(i+1);
		
	}
	if(v.empty()) cout<<"HE GOT AWAY!"<<'\n';
	else for(auto a:v) cout<<a<<' ';
	
	return 0;
}
