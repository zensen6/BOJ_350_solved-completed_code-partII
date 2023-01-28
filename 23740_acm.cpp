#include<bits/stdc++.h>
#define MAX 1000000001
using namespace std;


int n,s,e,c;
vector<pair<pair<int,int>,int>> Edge;

bool comp(pair<pair<int,int>,int> &a, pair<pair<int,int>,int> &b){
    if(a.first.first == b.first.first) return a.first.second < b.first.second; // <= 히면 안됨
    return a.first.first < b.first.first;
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);   
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s>>e>>c;
        Edge.push_back({{s,e},c});
    }
    sort(Edge.begin(),Edge.end(),comp);
    //
    //for(auto &p:Edge) cout<<p.first.first<<" "<<p.first.second<<" "<<p.second<<'\n';
    vector<pair<pair<int,int>,int>> ans;
    int start=0, end=0, cost=MAX;
    for(int i=0;i<n;i++){
        int s = Edge[i].first.first;
        int e = Edge[i].first.second;
        int c = Edge[i].second;
        if(i == 0){
            start = s, end = e, cost = c;
        }else{
            if(s <= end){
                end = max(end,e), cost = min(cost, c);
            }else{
                ans.push_back({{start,end},cost});
                start = s, end = e, cost = c;
            }
        }
    }
    ans.push_back({{start,end},cost});
    cout<<ans.size()<<'\n';
    for(auto &p:ans){
        cout<<p.first.first<<" "<<p.first.second<<" "<<p.second<<'\n';
    }

    return 0;
}