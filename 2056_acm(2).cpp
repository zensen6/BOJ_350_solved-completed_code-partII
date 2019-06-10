#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

int idg[10001] = {0};
int dest[10001] = {0};	
int price[10001] = {0};

bool comp(int a, int b){
	
	return a>b;
	
}
	
int main(){
	
	queue<int> q;
	
	vector<int> v[10001];
	
	int N, count;
	cin>>N;
	int from, cost;
	
	for(int i=1;i<=N;i++){
		cin>>cost;
		cin>>count;
		price[i] = dest[i] = cost;
		while(count>0){
			
			cin>>from;	
			idg[i]++;
			v[from].push_back(i);
			count--;
		}
		
	}
	
	
	int beg;
	for(beg = 1; beg <= N; beg++){
		
		if(!idg[beg]){
			
			q.push(beg);
			
		}
		
	}
	
	while(!q.empty()){
		
		int x = q.front();
		q.pop();
		for(auto &p: v[x]){
			
			idg[p]--;
			if(price[p] + dest[x] > dest[p]){
				
				dest[p] = price[p] + dest[x];
				
			}
			if(!idg[p]){
				
				q.push(p);
				
			}
			
		}
		
		
	}
	/*
	for(int i=1;i<=N;i++){
		cout<<dest[i]<<' ';
		
	}
	cout<<'\n';
	*/
	
	sort(dest+1, dest+N+1, comp);
	cout<<dest[1]<<'\n';
	return 0;
}
