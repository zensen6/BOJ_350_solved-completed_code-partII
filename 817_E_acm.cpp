#include<bits/stdc++.h>
using namespace std;


typedef long long ll;
int tc;
int n,q,x,y,h1,h2,w1,w2;
vector<pair<int,int>> arr;
ll node[300010];

bool comp(pair<int,int> &a, pair<int,int> &b){  
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

struct SegmentTree{
    void init(int start, int end, int node_index){
        if(start == end){
            node[node_index] = arr[start].first * ll(arr[start].second);
            return;
        }
        int mid = (start+end)>>1;
        init(start,mid,node_index<<1);
        init(mid+1,end,1+node_index*2);
        node[node_index] += (node[node_index*2] + node[1+node_index*2]);
        return;
    }

    ll query(int start, int end, int node_index, int h1, int w1, int h2, int w2){
        if(start == end && arr[start].first > h1 && arr[start].first < h2 && arr[start].second > w1 && arr[start].second < w2) return node[node_index];
        int mid = (start + end) >> 1;
        return query(start, mid, node_index<<1, h1, w1, h2, w2) +
        query(mid+1, end, 1+node_index*2, h1, w1, h2, w2);
    }

};


int main(){

    cin>>tc;
    while(tc--){
        arr.clear();
        ll ans = 0;
        cin>>n>>q;
        for(int i=0;i<n;i++){
            cin>>y>>x;
            arr.push_back({y,x});
        }
        sort(arr.begin(),arr.end(),comp);
        SegmentTree SG;
        //SG.init(0,n-1,1);
        for(int i=0;i<q;i++){
            cin>>h1>>w1>>h2>>w2;
            cout<<SG.query(0,n-1,1,h1,w1,h2,w2)<<'\n';
        }
        
    }
    return 0;
}