#include<bits/stdc++.h>
using namespace std;

int n,m,u,v;
vector<int> node[20001];
int d[20001];

int main(){

    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>u>>v;
        node[u].push_back(v);
        node[v].push_back(u);
    }
    queue<pair<int,int> > q;
    q.push(make_pair(1,0));
    
    while(!q.empty()){
        auto f = q.front();
        q.pop();
        int x = f.first, c = f.second;
        for(auto &p: node[x]){
            if(d[p] == 0 && p != 1){
                d[p] = c + 1;
                q.push(make_pair(p,d[p]));
            }
        }
    }
    int ans = 0, ans_f = n, ans_s = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans,d[i]);
    }
    for(int i=1;i<=n;i++){
        if(d[i] == ans){
            ans_f = min(ans_f, i);
            ans_s+=1;
        }
    }
    cout<<ans_f<<" "<<ans<<" "<<ans_s<<'\n';


    return 0;
}