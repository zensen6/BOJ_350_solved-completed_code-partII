#include <iostream>

using namespace std;

int parent[101];

int Find(int x){
	
	if(parent[x]==x) return x;
	else{
		
		int y = Find(parent[x]);
		return parent[x] = y;
	}
}

void Union(int x, int y){
	
	int x1 = Find(x);
	int y1 = Find(y);
	if(x1!=y1){
		
		if(x1<y1){
			
			parent[y1] = x1;
			Find(y);
			
		}else{
			
			parent[x1] = y1;
			Find(x);
			
		}
			
	}
}

int main(){
	
	int N,M;
	int x,y;
	int cnt=0;	
	cin>>N;
	cin>>M;
	for(int i=1;i<=N;i++) parent[i] = i;
	for(int i=1;i<=M;i++){
		
		cin>>x>>y;
		Union(x,y);		

	}
	for(int i=1;i<=N;i++){
		Find(i);
		if(parent[i]==1) cnt++; 
	}

	cout<<cnt-1<<'\n';
	return 0;
}
