#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>

using namespace std;

vector<int> v[10001];
vector<int> price[10001];
int ind[10001];

int main(){
	
	int max=0;
	int N;
	int t,C;
	int x,y;
	memset(ind,0,sizeof(ind));
	cin>>N;
	for(int i=1;i<=N;i++){
		
		cin>>t>>C;
		price[i].push_back(t);
		while(C--){
			
			cin>>x;
			v[x].push_back(i);
			ind[i]++;
			
		}
		
	}
	queue<int> q;
	for(int i=1;i<=N;i++){
		
		if(ind[i]==0)
			q.push(i);		
		
	}
	
	///

	
	///
	for(int i=1;i<=N;i++){
		
		x=q.front();
		q.pop();
		max=0;
		for(int k=0;k<v[x].size();k++){
			
			y = v[x][k];
			ind[y]--;
			
			if(price[x].back()+price[y].front()>max){
				
				max = price[x].back()+price[y].front();
				price[y].push_back(max);
				
			}
			
			if(ind[y]==0){
				
				q.push(y);
				
			}
			
		}
					
	}
	
	max= 0;
	for(int i=1;i<=N;i++){
		
		if(max<price[i].back()) max = price[i].back();
		
	}
	
	
	cout<<max<<'\n';
	
	return 0;
	
}
