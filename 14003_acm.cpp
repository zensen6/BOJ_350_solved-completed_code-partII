#include<bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int>> track;
vector<int> ans,ans_;
int x;

int main(){

    cin>>n; 
    
    for(int i=0;i<n;i++){
        cin>>x;
        if(ans.size() == 0 || (ans.size()&&ans.back()<x)){
            ans.push_back(x);
            track.push_back({ans.size()-1,x});
        }else{
            int idx = lower_bound(ans.begin(),ans.end(),x) - ans.begin();
            ans[idx] = x;
            track.push_back({idx,x});
        }
    } 
    int idx = ans.size()-1;
    for(int i=track.size()-1;i>=0;i--){
        if(track[i].first == idx){
            ans_.push_back(track[i].second);
            idx--;
        }
    }
    cout<<ans.size()<<'\n';
    reverse(ans_.begin(),ans_.end());
    for(auto &p: ans_) cout<<p<<" ";
    return 0;
}