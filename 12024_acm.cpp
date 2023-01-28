#include<bits/stdc++.h>

using namespace std;


typedef long long ll;
ll n,ans=0;
int arr[251][251];




int main(){

    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ll t = 0;
            for(int k=0;k<n;k++){
                if(i==j || i==k || j==k) continue;
                if(arr[i][k] && arr[k][j]){
                    t++;
                }
            }
            ans += ((t)*(t-1));
        }
    }
    cout<<ans<<'\n';

    return 0;
}