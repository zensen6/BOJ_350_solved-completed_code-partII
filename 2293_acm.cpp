#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int ans=0;

void go(vector<int>& v, int target, int index){
	
	if(target<0) return;
	if(index >= v.size()) return;
	if(target==0 && index<v.size()){
		ans+=1;
		return;
	}
	
		                                     //포문안돌린 이유는 i=index일때  go(v,target,index+1) 재귀호출 뒤 -> go(v,target-v[index],index) 와 i = index+1 일때 go(v,target-v[index+1],index+1) 이 같기때문이다. 즉 중복돼는게 너무 많음.                  
	go(v, target, index+1);
	go(v, target-v[index], index);
		
}


int main(){
	
	int n,k;
	cin>>n>>k;
	int x;
	vector<int>v;
	for(int i=0;i<n;i++){
		cin>>x;
		v.push_back(x);
		
	}
	sort(v.begin(),v.end());
	go(v,k,0);
	cout<<ans<<'\n';
	
	return 0;
}
