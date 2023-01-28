#include<bits/stdc++.h>
#define MOD 2000003LL
using namespace std;

typedef long long ll;
ll n;
int isPrime[3000001];
vector<ll> arr;

ll func(ll x,ll p){
    ll t = x;
    for(int i=1;i<p;i++) t*=x;
    return t;
}

int main(){

    for(int i=2;i<3000000;i++) isPrime[i] = 1;
    for(int i=2; i*i<3000000;i++){
        for(int j=i*i; j<3000000; j+=i){
            if(isPrime[i]) isPrime[j] = 0;
        }
    }


    cin>>n;
    for(int i=2;i<1458319+1;i++){
        if(isPrime[i]){
            arr.push_back(i);
            for(ll p=1LL; func(i,(1LL<<p))<1458319+1;p++){
                arr.push_back(func(i,(1LL<<p)));
            }
        }
    }
    sort(arr.begin(),arr.end());
    ll ans = 1LL;
    for(int i=0;i<n;i++){
        //cout<<arr[i]<<" ";
        ans*=arr[i];
        ans%=MOD;
    }
    cout<<ans<<'\n';
    //1458319가 111222번째 소수


    return 0;
}