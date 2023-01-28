#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;

int r,c,n,y,x,cost;
int m[3001][3001],d[3001][3001];
vector<pair<pair<int,int>,int>> pos;

int main(){

    for(int i=0;i<3001;i++){
        for(int j=0;j<3001;j++){
            d[i][j] = INF;
        }
    }
    cin>>r>>c;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>y>>x>>cost;
        m[y][x] = cost;
    }
    d[r][c] = 0;
    for(int i=r;i>=0;i--){
        for(int j=c;j>=0;j--){
            if(i+1<=r){
                d[i][j] = min(d[i][j], max(d[i+1][j]+1-m[i][j],0));
            }
            if(j+1<=c){
                d[i][j] = min(d[i][j], max(d[i][j+1]+1-m[i][j],0));
            }
        }
    }
    cout<<d[1][1]<<'\n';

    return 0;
}