#include<bits/stdc++.h>
using namespace std;

int n,m,depth[100001],parent[100001],pa[100001][18], candies[100001][18], candy[100001];
vector<int> node[100001];
int u,v,c;
int root;

bool query(int n1, int n2, int val){
    if(depth[n2] > depth[n1]) swap(n1,n2);
    int state = 0;
    state |= (1<<candy[n1]);
    state |= (1<<candy[n2]);
    int log2 = 0;
    for(;(1<<log2)<=depth[n1]-depth[n2];log2++){}
    log2--;
    for(;log2>=0;log2--){
        if(depth[n1]-depth[n2] >= (1<<log2)){
            state |= candies[n1][log2];
            n1 = pa[n1][log2];
        }
    }
    if(n1==n2) return ((((1<<val)&state)) > 0) ? true: false;

    log2 = 17;
    for(;log2>=0;log2--){
        if(pa[n1][log2]!=pa[n2][log2]){
            state |= candies[n1][log2];
            state |= candies[n2][log2];
            n1 = pa[n1][log2];
            n2 = pa[n2][log2];
        }
    }
    state |= (1<<candy[pa[n1][0]]);
    return (((1<<val)&(state)) > 0) ? true:false;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    queue<int> q;
    memset(depth,-1,sizeof(depth));
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>candy[i];
    }
    for(int i=0;i<n-1;i++){
        cin>>u>>v;
        node[u].push_back(v);
        node[v].push_back(u);
    }
    root = 1;
    depth[root] = 0;
    parent[root] = 1;
    q.push(root);
    while(!q.empty()){
        int f = q.front();
        q.pop();
        for(auto &p:node[f]){
            if(depth[p] == -1){
                parent[p] = f;
                depth[p] = depth[f] + 1;
                q.push(p);
            }
        }
    }   
    for(int i=1;i<=n;i++){
        pa[i][0] = parent[i];
        candies[i][0] |= (1<<candy[parent[i]]);
        candies[i][0] |= (1<<candy[i]);
    }
    for(int p=1; (1<<p) <= n; p++){
        for(int i=1;i<=n;i++){
            if(pa[i][p-1] != 0){
                pa[i][p] = pa[pa[i][p-1]][p-1];
                candies[i][p] |= candies[i][p-1];
                candies[i][p] |= candies[pa[i][p-1]][p-1];
            }
        }
    }


    cin>>m;
    int prev;
    for(int i=0;i<m;i++){
        cin>>u>>c;
        if(i==0){
            bool no = true;
            for(int j=1;j<=n;j++){
                if(candy[j] == c){
                    no=false;
                    break;
                }
            }
            if(no) cout<<"CRY"<<'\n';
            else cout<<"PLAY"<<'\n';
        }
        else{
            if(query(u,prev,c)) cout<<"PLAY"<<'\n';
            else cout<<"CRY"<<'\n';
        }
        prev = u;
    }
    /*
    for(int i=1;i<=5;i++){
        for(int p=0;p<=2;p++){
            cout<<candies[i][p]<<" ";
        }
        cout<<'\n';
    }
    */
    return 0;
}