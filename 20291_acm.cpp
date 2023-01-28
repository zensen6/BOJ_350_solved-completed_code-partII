#include<bits/stdc++.h>
using namespace std;

map<string,int> m;

int n;
string x;
int main(){

    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        int s = x.length();
        int j=0;
        for(j=0;j<s;j++){
            if(x[j] == '.') break;
        }
        m[x.substr(j+1,s-j)]++;
    }
    map<string,int>::iterator it;
    for(it=m.begin();it!=m.end();it++){
        cout<<it->first<<" "<<it->second<<'\n';
    }

    return 0;
}