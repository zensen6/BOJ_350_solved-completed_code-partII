#include<bits/stdc++.h>
using namespace std;

int n,c, discovered[51], visit = 0, sccId[51], scc_counter = 0;
string x,y;
vector<int> adj[51], vector<int> group_c[51];
stack<int> st;

int scc(int here){
	discovered[here] = visit++;
	int ret = discovered[here];
	st.push(here);
	for(auto &there: adj[here]){
		if(discovered[there] == -1){
			ret = min(ret, scc(there));
		}else if(sccId[there] == -1){
			ret = min(ret, discovered[there]);
		}
	}
	if(ret == discovered[here]){
		int c_ = 0;
		while(1){
			c_++;
			int t = st.top();
			st.pop();
			sccId[t] = scc_counter;
			if(t == here){
				group_c[scc_counter] = c_;
				break;
			}
		}
		scc_counter++;
	}
	return ret;
}

int main(){

	memset(discovered, -1, sizeof(discovered));
	memset(sccId,-1,sizeof(sccId));
	cin>>n;
	for(int i = 0 ; i < n; i++){
		cin>>x;
		cin>>c;
		for(int j = 0 ; j < c; j++){
			cin>>y;
			adj[int(x-'A')].push_back(int(y-'A'));
		}
	}
	cin>>x;




	return 0;

}
