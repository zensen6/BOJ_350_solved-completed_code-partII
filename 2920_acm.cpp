#include<iostream>
#include<vector>
using namespace std;

int main(){

	int x;
	vector<int> v;
	bool as=true;
	bool ds=true;
	cin>>x;
	v.push_back(x);
	for	(int i=1;i<8;i++){
		
		cin>>x;
		v.push_back(x);
		if(v[i]>v[i-1])ds=false;
		else as=false;
	}
	if(as) cout<<"ascending"<<'\n';
	else if(ds) cout<<"descending"<<'\n';
	else cout<<"mixed"<<'\n';
	
	return 0;
}
