#include<bits/stdc++.h>
#define INF 100000000009LL
using namespace std;

typedef long long ll;
int n,a,b,arr[36][36];
ll dist[1000];
int d[1000][1000];
int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1};
string x;
vector<pair<int,int> > node[1000];

bool inrange(int y, int x){
    return y>=1&&y<=n&&x>=1&&x<=n;
}

ll proc(int start){
    for(int i=1;i<1000;i++){
        dist[i] = INF;
    }
    dist[start] = 0;
    priority_queue<pair<ll,int>, vector<pair<ll,int> >, greater<pair<ll,int> > > pq;
    pq.push(make_pair(0,start));
    while(!pq.empty()){
        auto f = pq.top();
        pq.pop();
        int now = f.second;
        ll cost = f.first; 
        if(dist[now] < cost) continue;
        for(auto &next: node[now]){
            int target = next.first, cost_ = next.second;
            if(dist[target] > dist[now] + cost_){
                dist[target] = dist[now] + cost_;
                pq.push(make_pair(dist[target],target));
            }
        }
    }
    ll ans = 0;
    for(int i=1;i<=n*n;i++){
        //cout<<start<<" "<<i<<" "<<dist[i]<<'\n';
        ans = max<ll>(ans, dist[i]);
    }
    return ans;
}

int main(){

    cin>>n>>a>>b;
    for(int i=1;i<=n;i++){
        cin>>x;
        for(int j=1;j<=n;j++){
            if(x[j-1] == '(') arr[i][j] = 0;
            else arr[i][j] = 1;
        }
    }
    /*
    for(int i=1;i<=n;i++){
        for(int j=1; j<=n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<'\n';
    }
    */

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int dir=0;dir<4;dir++){
                int ny = i + dy[dir], nx = j + dx[dir];
                if(inrange(ny,nx)){
                    if(arr[i][j] != arr[ny][nx]){
                        //d[(i-1)*n + j][(ny-1)*n + nx] = b;
                        node[(i-1)*n + j].push_back(make_pair((ny-1)*n + nx,b));
                        node[(ny-1)*n + nx].push_back(make_pair((i-1)*n + j,b));
                    }else{
                        //d[(i-1)*n + j][(ny-1)*n + nx] = a;
                        node[(i-1)*n + j].push_back(make_pair((ny-1)*n + nx,a));
                        node[(ny-1)*n + nx].push_back(make_pair((i-1)*n + j,a));
                    }
                }
            }
        }
    }
    ll ans = 0;
    for(int start = 1; start<=n*n; start++){
        ans = max<ll>(ans, proc(start));
    }
    cout<<ans<<'\n';

    return 0;
}