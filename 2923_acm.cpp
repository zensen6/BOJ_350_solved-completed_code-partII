#include<bits/stdc++.h>
using namespace std;

int t,a,b;
int A[101], B[101];
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>a>>b;

        A[a]++;
        B[b]++;
        int arrA[101], arrB[101];
        for(int j=0;j<101;j++){
            arrA[j] = A[j];
            arrB[j] = B[j];
        }
        int l=1, r=100;
        int ans = 0;
        while(l<=100 && r>=1){
            while(arrA[l] == 0 && l<=100) l++;
            while(arrB[r] == 0 && r>=1) r--;
            if(r<1 || l>100) break;
            ans = max(ans, l+r);
            int minidx = min(arrA[l],arrB[r]);
            if(minidx == arrA[l] && minidx == arrB[r]){
                arrA[l] = 0;
                arrB[r] = 0;
            }else{
                arrB[r] -= minidx;
                arrA[l] -= minidx;
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}