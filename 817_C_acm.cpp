#include<bits/stdc++.h>
using namespace std;

int tc;
int n;

map<string,int> m;

int main(){
    cin>>tc;
    while(tc--){
        string x;
        int A=0,B=0,C=0;
        m.clear();
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>x;
            m[x]+=1;
        }
        for(int i=0;i<n;i++){
            cin>>x;
            m[x]+=2;
        }
        for(int i=0;i<n;i++){
            cin>>x;
            m[x]+=4;
        }
        map<string,int>::iterator it;
        for(it=m.begin();it!=m.end();it++){
            if(it->second == 1){
                A+=3;
            }else if(it->second == 2){
                B+=3;
            }else if(it->second == 3){
                A+=1;
                B+=1;
            }else if(it->second == 4){
                C+=3;
            }else if(it->second == 5){
                A+=1;
                C+=1;
            }else if(it->second == 6){
                B+=1;
                C+=1;
            }else if(it->second == 7){
                
            }
        }
        cout<<A<<" "<<B<<" "<<C<<'\n';

    }

    return 0;
}