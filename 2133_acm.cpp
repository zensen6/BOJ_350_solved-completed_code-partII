#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll dp[31][3] = {0,};

int main(){

    int N;
    cin>>N;
    dp[2][0] = 3LL;
    dp[2][1] = 1LL;
    dp[2][2] = 1LL;

    dp[0][0] = 0LL;
    dp[0][1] = dp[0][2] = 0LL;
    if(N&1){

        cout<<0<<'\n';
        return 0;

    }
    else{

        for(int i=4;i<=N;i+=2){

            dp[i][1] = dp[i-4][0] + dp[i-2][1];
            dp[i][2] = dp[i-4][0] + dp[i-2][2];
            dp[i][0] = dp[i-2][0]*3 + dp[i][1] + dp[i][2];

        }
        cout<<dp[N][0]<<'\n';
    }

    return 0;
}