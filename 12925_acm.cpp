#include<bits/stdc++.h>
#define MOD 1000000000LL
using namespace std;

typedef long long ll;
int tc,n,c=0;

ll mod(ll x, ll y){
    if(x%y < 0) return x%y+y;
    else return x%y;
}

ll trans_(ll x){
  return x%MOD;
}

class matrix{
    public:
    int sizeofm;
    vector<vector<ll>> m;
    matrix(int n):sizeofm(n){}
    matrix(int n, vector<vector<ll>> v):sizeofm(n){
        m.resize(n,vector<ll>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                m[i][j] = v[i][j];
            }
        }
    }
};

vector<vector<ll>> mul(vector<vector<ll>> A, vector<vector<ll>> B){
    vector<vector<ll>> C(2,vector<ll>(2,0));
    for(int row=0;row<2;row++){
        for(int col=0;col<2;col++){
            ll sum = 0;
            for(int i=0;i<2;i++){
                sum += A[row][i] * B[i][col];
                sum = trans_(sum);
            }
            C[row][col] = sum;
        }
    }
    return C;
}

vector<vector<ll>> identity(){
    vector<vector<ll>> I(2,vector<ll>(2,0));
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            if(i==j) I[i][j] = 1LL;
            else I[i][j] = 0;
        }
    }
    return I;
}

vector<vector<ll>> power(matrix &A, long long B){
    if(B == 0) return identity();
    else if(B == 1) return A.m;
    else if(B & 1){
        vector<vector<ll>> tmp = power(A,B/2);
        return mul(A.m,mul(tmp,tmp));
    }
    else{
        vector<vector<ll>> tmp = power(A,B/2);
        return mul(tmp,tmp);
    }
}

int main(){

  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>tc;
  vector<vector<ll>> v(2,vector<ll>(2,0));
  v[0][0] = 6LL;
  v[0][1] = -4LL;
  v[1][0] = 1LL;
  v[1][1] = 0;
  matrix Ir(2,v);
  while(tc--){
    cin>>n;
    vector<vector<ll>> nIr = power(Ir,n-1);
    ll ans_ll = mod(mod(nIr[0][0]*6LL+nIr[0][1]*2LL-1LL,MOD),MOD)%1000LL;
    string ans = to_string(ans_ll);
    if(ans_ll < 100) ans = "0" + ans;
    if(ans_ll < 10) ans = "0" + ans;
    cout<<"Case #"<<++c<<": "<<ans<<'\n';
  }


  return 0;
}
