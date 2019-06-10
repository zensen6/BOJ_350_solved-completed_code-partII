#include<iostream>
#include<vector>
#include<algorithm>
#include<memory.h>
#include<queue>

using namespace std;

int idg[32001] = {0};
int arr[32001] = {0};

int main(){
	
	queue<int> q;
	vector<int> v[32001];
	
	int n,m;
	cin>>n>>m;
	int from ,to;
	for(int i=0;i<m;i++){
		
		cin>>from>>to;
		v[from].push_back(to);
		idg[to]++;
		
	}
	int begin;
	for(begin=1;begin<=n;begin++){
		
		if(!idg[begin]){
			
			q.push(begin);
			
		}
		
	}
	int cnt = 0;
	while(!q.empty()){
		
		int x= q.front();
		q.pop();
		arr[cnt++] = x;
		for(auto &p: v[x]){
			
			idg[p]--;
			if(!idg[p]){
				
				q.push(p);
				
			}
			
		}
		
		
	}
	
	for(int i=0;i<cnt;i++){
		cout<<arr[i]<<' ';
		
	}
	return 0;
}
