#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int arr[10001];
ll sum[10001];
int main(){

    ll total = 0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){

        cin>>arr[i];

    }
    sort(arr+1,arr+1+n);
    if(n==1){

        cout<<0<<'\n';
        return 0;

    }
    
    else{

        for(int i=2;i<=n;i++){

            sum[1] += (arr[i]-arr[1]);
        }
        for(int i=2;i<=n;i++){

            sum[i] = (i-1)*(arr[i]-arr[i-1]) - (n-i+1)*(arr[i]-arr[i-1]) + sum[i-1];

        }

    }

    for(int i=1;i<=n;i++ )total+=sum[i];
    cout<<total<<'\n';
    return 0;
}