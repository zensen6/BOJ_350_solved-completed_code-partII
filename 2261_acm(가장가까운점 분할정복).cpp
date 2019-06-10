#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>

using namespace std;

long long ans;
long long min0=9999999999;

vector< pair<int,int> >nv;
vector< pair<int,int> >v;

long long dis(pair<int, int>a, pair<int, int>b){
	
	return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
	
}

void findleast(int start, int end){
	
	if(start == end) return;
	if(start+1==end){
		
		ans = dis(nv[start],nv[end]);
		if(min0>ans) min0=ans;
		return;
		
	}
	int mid = (start+end)/2;
	findleast(start,mid);
	findleast(mid,end);
	
}

bool comp(pair<int,int>a, pair<int,int>b){

	if(a.first==b.first){
		
		return a.second<=b.second;
		
	}
	else{
		
		return a.first<=b.first;
		
	}
}
int main(){
	
	int N;
	cin>>N;
	int x; int y;
	
	for(int i=0;i<N;i++){
			cin>>x>>y;
			v.push_back(make_pair(x,y));
	}	
	sort(v.begin(),v.end(),comp);
	for(int i=0;i<v.size();i++){
		
		if(i!=0 && (v[i].first==v[i-1].first) && (v[i].second == v[i-1].second)){
			
			continue;
			
		}
		else{
			
			nv.push_back(make_pair(v[i].first,v[i].second));
			
		}
		
		
	}

	findleast(0,nv.size()-1);
	cout<<min0<<'\n';
	return 0;
}
