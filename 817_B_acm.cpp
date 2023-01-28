#include<bits/stdc++.h>
using namespace std;

string x,y;

int tc;
int n;
int main(){

    cin>>tc;
    while(tc--){
        cin>>n;
        cin>>x;
        cin>>y;
        bool yes = true;
        for(int i=0;i<n;i++){
            if((x[i]=='G'&&y[i]=='R') || (x[i]=='R'&&y[i]=='G') || (x[i]=='B'&&y[i]=='R') || (x[i]=='R'&&y[i]=='B')){
                yes = false;
                break;
            }
        }
        if(yes) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }

    return 0;
}