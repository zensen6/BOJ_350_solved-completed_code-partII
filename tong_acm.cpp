#include<bits/stdc++.h>
using namespace std;

vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        map<int,int> m;
        vector<pair<int,int>> v;
        for(auto & p : logs){
            v.push_back({p[0],p[1]});
        }
        sort(v.begin(),v.end());
        int pid = v[0].first, c = 0;
        int len = v.size();
        map<int,int> init;
        for(int i = 0; i < len; i++){
            //cout<<v[i].first<<" "<<v[i].second<<'\n';
            if(pid == v[i].first){
                 init[v[i].second]++;
            }else{
                c = init.size();
                m[c]++;
                pid = v[i].first;
                init.clear();
                init[v[i].second]++;
            }
        }
        c = init.size();
        m[c]++;
        vector<int> ans = vector<int>(k,0);
        for(auto k: m) ans[k.first-1] = k.second;
        return ans;
    }

int main(){

  int k, s, x,y;
  vector<vector<int>> logs;
  cin>>k>>s;
  for(int i = 0; i < s; i++){
    cin>>x>>y;
    logs.push_back({x,y});
  }
  vector<int> ans = findingUsersActiveMinutes(logs, k);
  for(auto p: ans) cout<<p<<" ";

  return 0;
}
