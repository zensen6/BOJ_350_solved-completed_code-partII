#include<bits/stdc++.h>
using namespace std;

int pa[100001][20],parent[100001],depth[100001];
int n,m,u,v;
vector<int> node[100001];


int lca(int n1, int n2){
    if(depth[n1] < depth[n2]) swap(n1,n2);
    int log2 = 0;
    for(;(1<<log2)<=(depth[n1]-depth[n2]);log2++){}
    log2--;
    for(;log2>=0;log2--){
        if(depth[n1]-depth[n2] >= (1<<log2)){
            n1 = pa[n1][log2];
        }
    }
    if(n1==n2) return n1;
    log2 = 19;
    for(;log2>=0;log2--){
        if(pa[n1][log2] != pa[n2][log2]){
            n1 = pa[n1][log2];
            n2 = pa[n2][log2];
        }
    } 
    return parent[n1];
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    memset(depth,-1,sizeof(depth));
    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        node[u].push_back(v);
        node[v].push_back(u);
    }
    depth[1] = 0;
    parent[1] = 1;
    queue<int> q;
    q.push(1);
    while(!q.empty()){
        int f = q.front();
        q.pop();
        for(auto &next:node[f]){
            if(depth[next] == -1){
                depth[next] = depth[f] + 1;
                parent[next] = f;
                q.push(next);
            }
        }
    }

    for(int i=1;i<=n;i++) pa[i][0] = parent[i];
    for(int p=1;(1<<p)<=n;p++){
        for(int j=1;j<=n;j++){
            pa[j][p] = pa[pa[j][p-1]][p-1];
        }
    }

    cin>>m;
    while(m--){
        cin>>u>>v;
        cout<<lca(u,v)<<'\n';
    }

    return 0;
}