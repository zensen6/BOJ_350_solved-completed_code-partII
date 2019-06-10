#include<iostream>
#include<vector>
#include<memory.h>
#include<queue>
using namespace std;
vector<int> v[32001];
int ind[32001];

void topology(int N){
	
	int size = N-1;	
	queue<int> q;
	for(int i=1;i<=N;i++){
		if(!ind[i]){
			q.push(i);	
		}	
	}
	for(int i=1;i<=N;i++){
		
		int x = q.front();
		q.pop();
		cout<<x<<' ';
		for(int k=0;k<v[x].size(); k++){
			
			int y=v[x][k];
			ind[y]-=1;
			if(ind[y]==0){
				
				q.push(y);
				
			}
				
		}
	
		
	}
		
}

int main(){
	
	int N,M;
	int x,y;
	cin>>N>>M;
	memset(ind,0,sizeof(ind));
	
	for(int i=0;i<M;i++){
		
		cin>>x>>y;
		v[x].push_back(y);
		ind[y]+=1;	
		
	}
	
	topology(N);
	
	return 0;
}
