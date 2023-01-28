#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

int tc,n;
string x;
ll arr[200010];
ll s = 0;
int main(){

    cin>>tc;
    while(tc--){
        for(int i=0;i<200010;i++) arr[i] = 0;
        cin>>n; 
        cin>>x;
        int c=1;
        s = 0;
        for(int i=0;i<(n>>1);i++){
            if(x[i]=='R') s+=(n-1ULL-i);
            else if(x[i]=='L'){
                s+=i;
                arr[c] += arr[c-1]; 
                arr[c++] += (n-1ULL-2*i);
            }
            if(x[n-1-i]=='R'){
                s+=i;
                arr[c] += arr[c-1];
                arr[c++] += (n-1ULL-2*i);
            }
            else if(x[n-1-i]=='L') s+=(n-1LL-i);
        }
        if(n&1) s+=(n>>1);
        while(c<200010) arr[c++] += arr[c-1];
        for(int k=1;k<n;k++){
            cout<<s+arr[k]<<" ";
        }
        cout<<s+arr[n]<<'\n';
    }

    return 0;
}