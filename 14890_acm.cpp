#include<bits/stdc++.h>
using namespace std;

int n,l;
int arr[102][102];

int main(){

    cin>>n>>l;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>arr[i][j];
        }
    }
    int ans=0;  
    for(int j=1;j<=n;j++){
        vector<pair<int,int> > pos;
        int s = 1,e = 1;
        while(s<=n){
            if(arr[e][j] == arr[s][j]){
                e++;
                if(e > n){
                    pos.push_back(make_pair(e-s,arr[s][j]));
                    break;
                }
            }else{
                pos.push_back(make_pair(e-s,arr[s][j]));
                s = e;
            }
        }
        int le = pos.size();
        bool cannot = false;
        for(int k=0;k<le;k++){
            if(k==0){
                if(k+1 < le){
                    if(pos[k+1].second == pos[k].second + 1 && pos[k].first >= l){
                        continue;
                    }else if(pos[k+1].second + 1 == pos[k].second){
                        continue;
                    }else{
                        cannot = true;
                        break;
                    }
                }else{ // 블록 한개인경우
                    break;
                }
            }else if(k==le-1){
                if(pos[k-1].second == pos[k].second + 1 && pos[k].first >= l){
                    continue;
                }else if(pos[k-1].second + 1 == pos[k].second && pos[k-1].first >= l){
                    continue;
                }else{
                    cannot = true;
                    break;
                }
            }else{
                if(pos[k-1].second == pos[k].second + 1 && pos[k+1].second == pos[k].second+1 && pos[k].first >= 2*l){
                    continue;
                }else if(pos[k-1].second == pos[k].second + 1 && pos[k+1].second +1 == pos[k].second && pos[k].first >= l && pos[k+1].first >= l){
                    continue;
                }else if(pos[k-1].second +1 == pos[k].second && pos[k+1].second +1 == pos[k].second && pos[k-1].first >= l && pos[k+1].first >= l){
                    continue;
                }else if(pos[k-1].second +1 == pos[k].second && pos[k+1].second == pos[k].second + 1 && pos[k-1].first >= l && pos[k].first >= l){
                    continue;
                }else{
                    cannot = true;
                    break;
                }
            }
        }
        if(cannot == false){
            ans++;
        }
    }





    for(int i=1;i<=n;i++){
        vector<pair<int,int> > pos;
        int s = 1,e = 1;
        while(s<=n){
            if(arr[i][e] == arr[i][s]){
                e++;
                if(e > n){
                    pos.push_back(make_pair(e-s,arr[i][s]));
                    break;
                }
            }else{
                pos.push_back(make_pair(e-s,arr[i][s]));
                s = e;
            }
        }
        int le = pos.size();
        bool cannot = false;
        for(int k=0;k<le;k++){
            if(k==0){
                if(k+1 < le){
                    if(pos[k+1].second == pos[k].second + 1 && pos[k].first >= l){
                        continue;
                    }else if(pos[k+1].second + 1 == pos[k].second){
                        continue;
                    }else{
                        cannot = true;
                        break;
                    }
                }else{ // 블록 한개인경우
                    break;
                }
            }else if(k==le-1){
                if(pos[k-1].second == pos[k].second + 1 && pos[k].first >= l){
                    continue;
                }else if(pos[k-1].second + 1 == pos[k].second && pos[k-1].first >= l){
                    continue;
                }else{
                    cannot = true;
                    break;
                }
            }else{
                if(pos[k-1].second == pos[k].second + 1 && pos[k+1].second == pos[k].second+1 && pos[k].first >= 2*l){
                    continue;
                }else if(pos[k-1].second == pos[k].second + 1 && pos[k+1].second +1 == pos[k].second && pos[k].first >= l && pos[k+1].first >= l){
                    continue;
                }else if(pos[k-1].second +1 == pos[k].second && pos[k+1].second +1 == pos[k].second && pos[k-1].first >= l && pos[k+1].first >= l){
                    continue;
                }else if(pos[k-1].second +1 == pos[k].second && pos[k+1].second == pos[k].second + 1 && pos[k-1].first >= l && pos[k].first >= l){
                    continue;
                }else{
                    cannot = true;
                    break;
                }
            }
        }
        if(cannot == false){
            ans++;
        }
    }

    cout<<ans<<'\n';

    return 0;
}