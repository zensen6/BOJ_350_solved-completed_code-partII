#include<bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;

typedef long long ll;

ll gcd(ll x, ll y){
    if(y==0) return x;
    return gcd(y,x%y);
}
int tc;
ll n,m;

vector<vector<ll>> arr(2,vector<ll>(2,0));
vector<vector<ll>> I(2,vector<ll>(2,0));

vector<vector<ll>> multi(vector<vector<ll>> A, vector<vector<ll>> B){
    vector<vector<ll>> ans(2,vector<ll>(2,0));
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                ans[i][j] += A[i][k]*B[k][j]; 
                ans[i][j] %= MOD;
            }
        }
    }
    return ans;
}
vector<vector<ll>> power(ll n){
    if(n==0) return I;
    else if(n==1LL) return arr;
    vector<vector<ll>> tmp = power(n>>1LL);
    if(n&1LL){
        return multi(arr,multi(tmp,tmp));
    }
    return multi(tmp,tmp);
}

int main(){

    arr[0][0] = 1LL,arr[0][1] = 1LL,arr[1][0] = 1LL,arr[1][1] = 0;
    I[0][0] = 1LL, I[0][1] = 0, I[1][0] = 0, I[1][1] = 1LL;

    cin>>tc;
    while(tc--){
        cin>>n>>m;
        ll GCD = gcd(n,m);
        vector<vector<ll>> ans = power(GCD-1);
        
        
         
        cout<<ans[0][0] %MOD<<'\n';

    }



    return 0;
}