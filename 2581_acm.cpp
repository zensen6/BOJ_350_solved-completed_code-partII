#include<iostream>
#include<vector>
using namespace std;

int main(){
	
	vector<int> v;
	bool isprime = true;
	int m,n;
	int sum=0;
	cin>>m>>n;
	if (m==1) m+=1;
	for(int i=m;i<=n;i++){
	
		for(int k=2;k*k<=i;k++){
			
			if(i%k==0){
				isprime = false;
				break;
				
			}
			
		}
		if(isprime) v.push_back(i);
		isprime = true;
		
	}
	if(v.empty()){
		
		cout<<-1<<'\n';
	}
	else{
		vector<int>::iterator it;
		for(it = v.begin();it!=v.end();it++){
		
			sum+=*it;
		
		}
	
		cout<<sum<<'\n';
		cout<<v[0]<<'\n';
		return 0;
			
	}
	return 0;
}
