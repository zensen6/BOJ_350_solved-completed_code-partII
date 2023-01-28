#include<bits/stdc++.h>
using namespace std;

int tc,n;
string x = "";

int bijection(int x, int y, int z){
	if(z){
		return (x+100)*20000 + y;
	}
	return (x)*20000 + y;
}

vector<pair<int,int>> rev[20000];
int check[20000];
int revs = 0;

bool proc(){
	queue<int> q;
	q.push(1); //  cur_mod = 1
	check[1] = 1;
	while(!q.empty()){
		auto mod = q.front();
		q.pop();
		int mod0 = (mod*10)%n;
		if(!check[mod0]){
			check[mod0] = check[mod] + 1;
			rev[mod0].push_back({0,mod});
			if(mod0 == 0){
				revs = 0;
				return true;
			}
			q.push(mod0);
		}
		int mod1 = (mod*10 + 1)%n;
		if(!check[mod1]){
			check[mod1] = check[mod] + 1;
			rev[mod1].push_back({1,mod});
			if(mod1 == 0){
				revs = 1;
				return true;
			}
			q.push(mod1);
		}
	}

	return false;
}


void dfs2(int here){
	if(here == 1){
		check[here] = true;
		return;
	}
	check[here] = true;
	for(auto &p: rev[here]){
		if(!check[p.second]){
			int one = p.first;
			x += to_string(one);
			dfs2(p.second);
			break;
		}
	}
	return;
}


int main(){
	cin>>tc;
	while(tc--){
		revs = 0;
		memset(check, false, sizeof(check));
		for(int i=0;i<20000;i++){
			rev[i].clear();
		}
		cin>>n;
		x="";
		if(proc()){
			memset(check, false, sizeof(check));
			dfs2(0);
			x+="1";
			reverse(x.begin(),x.end());
			cout<<x<<'\n';
		}else{
			cout<<"BRAK"<<'\n';
		}

	}



	return 0;
}
