#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
int n,x;
bool isPrime[500010];
ll d[2][500010];
vector<int> arr;
map<int,int> m;
int sum=0;

int main(){

    for(int i=2;i<500010;i++) isPrime[i] = true;
    for(int i=2;i*i<500010;i++){
        if(isPrime[i]){
            for(int j=i*i;j<500010;j+=i){
                isPrime[j] = false;
            }
        }
    }

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        m[x]++;
        arr.push_back(x);
        sum+=x;
    }
    sort(arr.begin(),arr.end());
    arr.erase(unique(arr.begin(),arr.end()),arr.end());
    int s = arr.size();
    for(int k=sum; k>=0; k--){
        if(isPrime[k]) d[s%2][k] = 1LL;
    }
    ll ans=0;
    for(int i=s;i>=1;i--){
        for(int j=0;j<=m[arr[i-1]];j++){
            for(int k=sum; k>=0; k--){
                if(k>=j*arr[i-1]){
                    d[(i-1)%2][k-j*arr[i-1]] += d[i%2][k];
                }
            }
        }
        for(int k=sum; k>=0; k--){
            d[i%2][k] = 0;
        }
    }
    
    cout<<d[0][0]<<'\n';

    return 0;
}