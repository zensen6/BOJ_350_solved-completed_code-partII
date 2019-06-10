#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool comp(int a, int b){
	return a>=b;
}

int main(){
	
	int N;
	cin>>N;
	int x;
	vector<int> v;	
	
	for(int i=1;i<=N;i++){
	
		cin>>x;	
		v.push_back(x);
	} 
	
	sort(v.begin(),v.end());
	for(int i=N+1;i<=N*N;i++){
		
		cin>>x;
		int j=0;
		for(j=0;j<v.size();j++){   //vector는 맨끝인덱스넘어가면 크기비교가 곤란하므로 그냥 for문 을 돌리는것이좋다. 
			if(x>v[j]) continue;
			else break;
		}
		if(j==0){}
		else{
			
			j--;
			for(int k=0;k<j;k++){
			
				v[k] = v[k+1];
			
			}
			v[j]=x;
			
		}
		
	}

	cout<<v[0]<<'\n';
	return 0;
	
	
}
