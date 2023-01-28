#include<bits/stdc++.h>
using namespace std;

int n,tc;
string x;
int alpha[26],Dlpha[26];
int main(){

    cin>>tc;
    while(tc--){
        memset(alpha,0,sizeof(alpha));
        memset(Dlpha,0,sizeof(Dlpha));
        bool yes = true;
        cin>>n;
        if(n != 5) yes = false;
        cin>>x;
        for(auto &p:x){
            if(p >= 'a' && p <= 'z'){
                alpha[p-'a']++;
            }else if(p>= 'A' && p<= 'Z'){
                Dlpha[p-'A']++;
            }
        }
        //for(int i=0;i<26;i++) cout<<alpha[i]<<" ";
        if(alpha[8]==1 && alpha[12]==1 && alpha[17]==1 && alpha[20]==1 && Dlpha[19]==1){
            yes=true;
        }else yes=false;
        if(yes) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }

    return 0;
}