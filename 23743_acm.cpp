#include<bits/stdc++.h>
using namespace std;

int n,m,u,v,c;
typedef long long ll;
vector<pair<pair<int,int>,int>> adj;
int out[200001], parent[200001];


int Find(int x){
    if(parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y){
    int x1 = Find(x), y1 = Find(y);
    if(x1 < y1){
        parent[y1] = x1;
        Find(y);
    }else{
        parent[x1] = y1;
        Find(x);
    }
    return;
}

bool comp(pair<pair<int,int>,int> &a, pair<pair<int,int>,int> &b){
    return a.second < b.second;
}

ll ans = 0;
int main(){

    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>u>>v>>c;
        adj.push_back({{v,u},c});
        adj.push_back({{u,v},c});
        
    }
    for(int i=1;i<=n;i++){
        cin>>out[i];
        adj.push_back({{0,i},out[i]});
        adj.push_back({{i,0},out[i]});
        parent[i] = i;
    }
    sort(adj.begin(),adj.end(),comp);

    int s = adj.size();
    for(int i=0;i<s;i++){
        int u1 = adj[i].first.first, u2 = adj[i].first.second, cost = adj[i].second;
        if(Find(u1) != Find(u2)){
            Union(u1,u2);
            ans += cost;
        }
    }

    cout<<ans<<'\n';
    return 0;
}