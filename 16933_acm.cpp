#include<bits/stdc++.h>
using namespace std;

int n,m,k;
int arr[1001][1001];
int d[1001][1001][11][2];

bool inrange(int y, int x){
    return y>=0&&y<n&&x>=0&&x<m;
}

int proc(){

    int y, x, b, flag;
    d[1][1][0][0] = 1;
    queue<tuple<int, int, int, int> > q;
    q.push(make_tuple(1, 1, 0, 0));
    while(!q.empty()){
        tie(y, x, b, flag) = q.front();
        q.pop();


    }


}

int main(){
    cin>>n>>m>>k;
    string x;
    for(int i=0;i<n;i++){
        cin>>x;
        for(int j=0;j<m;j++){
            arr[i][j] = int(x[j] -'0');
        }
    }





    return 0;
}