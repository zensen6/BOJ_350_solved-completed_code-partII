#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, k;
ll d[52][52];

string kth(int i, int l, ll k){
    string ans = "";
    if(i == n+1 && k == 0) return ans;
    else if(l == (n>>1)) {
        for(int z=0;z<n-i+1;z++) ans += ")";
        return ans;
    }
    ll j = 2*l - i + 1;
    if(k <= d[i][j+1]){
        ans += "(";
        ans += kth(i+1, l+1, k);
    }else{
        ans += ")";
        ans += kth(i+1, l, k-d[i][j+1]);
    }
    return ans;

}


int main(){

    cin>>n>>k;
    d[n-1][1] = 1LL;
    for(int i=n-2;i>=1;i--){
        for(int j=0;j<=(n>>1);j++){
            if(j==0){
                d[i][j] += d[i+1][j+1];
            }else if(j==(n>>1)){
                d[i][j] += d[i+1][j-1];
            }else{
                d[i][j] += (d[i+1][j-1] + d[i+1][j+1]);
            }
        }
    }
    if(k+1 > d[1][1]){
        cout<<-1<<'\n';
    }else{
        cout<<"(" + kth(2,1,k+1)<<'\n';
    }
    

    return 0;
}



/*
(
 2번째에서 d[2][2] 보다 크면 
     
여태 (를 l개 사용 => 

*/