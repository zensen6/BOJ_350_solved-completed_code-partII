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
	
		                                     //�����ȵ��� ������ i=index�϶�  go(v,target,index+1) ���ȣ�� �� -> go(v,target-v[index],index) �� i = index+1 �϶� go(v,target-v[index+1],index+1) �� ���⶧���̴�. �� �ߺ��Ŵ°� �ʹ� ����.                  
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
