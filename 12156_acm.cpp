#include<bits/stdc++.h>
using namespace std;

int t;
int r,c,n;

int main(){

    cin>>t;
    int z=1;
    while(t--){
        int ans = 0;
        cin>>r>>c>>n;
        ans = (r-1)*c + (c-1)*r;
        n = r*c - n;

        if(r > c) swap(r,c);
        if(r==2){
            if(n >= c-2){
                n -= (c-2);
                ans -= (c-2)*3;
            }else{
                ans -= n*3;
                n = 0;
            }
            ans -= min(2,n)*2;
        }else if(r==1){
            if(c&1){
                ans -= min((c-1)/2, n)*2;
            }else{
                if(n >=(c/2 -1)){
                    ans -= 2*(c/2 -1);
                    n -= (c/2 -1);
                }else{
                    ans -=2*n;
                }
                ans -= min(1,n);
            }
        }
        else{
            if(c&1 && r&1){
                if(r==3&&c==3&&n==4){
                    ans = 0;
                }else{
                    if(n >= (int((r-2)*(c-2))/2 +1)){
                        int erase = int(((r-2)*(c-2))/2)+1;
                        ans -= erase*4;
                        n -= erase;
                    }else{
                        ans -= 4*n;
                        n = 0;
                    }
                    if(n >= (int((r-2)/2)*2 + int((c-2)/2)*2)){
                        int erase = int((r-2)/2)*2 + int((c-2)/2)*2;
                        ans -= erase*3;
                        n -=erase;
                    }else{
                        ans -= 3*n;
                        n = 0;
                    }
                    ans -= min(n,4)*2;
                }
                
            }else{
                if(n >= (r-2)*(c-2)/2){
                    int erase = (r-2)*(c-2)/2;
                    ans -= 4*erase;
                    n -=erase;
                }else{
                    ans -= 4*n;
                    n = 0;
                }
                if(n >= r-2 + c-2){
                    int erase = r-2+c-2;
                    ans -= 3*erase;
                    n -= erase;
                }else{
                    ans -= 3*n;
                    n = 0;
                }
                ans -= min(n,2)*2;
            }
        }
        cout<<"Case #"<<z<<": "<<ans<<'\n';
        z++;
    }



    return 0;
}