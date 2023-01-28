#include<bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;

typedef long long ll;
int n,r;
ll A,B,C,R;

ll go(ll x, ll y){
    if(y == 0) return 1LL;
    else if(y == 1LL) return x;
    else{
        ll tmp = go(x,y>>1LL);
        if(y&1){
            return (((tmp*tmp)%MOD)*x)%MOD;
        }else{
            return (tmp*tmp)%MOD;
        }
    }
}


int main(){

    cin>>n>>r;
    A=1LL, B=1LL, C=1LL;
    for(int i=1;i<=n;i++){
        A*=i;
        A%=MOD;
    }
    for(int i=1;i<=n-r;i++){
        B*=i;
        B%=MOD;
    }
    for(int i=1;i<=r;i++){
        C*=i;
        C%=MOD;
    }
    R = (B*C)%MOD;
    cout<<(A*(go(R,MOD-2LL)%MOD))%MOD<<'\n';
    //A*(R)^(p-2) 구하기

    return 0;
}