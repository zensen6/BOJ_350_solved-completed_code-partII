#include<bits/stdc++.h>
#define MP make_pair

//typedef pair<int,int> P;

using namespace std;
pair<int,int> arr[1000001];

bool comp( pair<int,int>&a, pair<int,int> &b){

    return a.first < b.first;

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int maxlen = -1;
    int n;
    int left, right;
    int lineR;
    cin>>n;
    for(int i=1;i<=n;i++){

        cin>>left>>right;
        arr[i] = MP(left,right);
    }

    sort(arr+1, arr+1+n,comp);
    //for(int i=1;i<=n;i++) cout<<arr[i].first<<' '<<arr[i].second<<'\n';
    for(int i=1;i<=n;i++){

        if(maxlen==-1){

            lineR = arr[i].second;
            maxlen = lineR-arr[i].first;
            //cout<<maxlen<<'\n';
        } 

        else if(lineR < arr[i].second && lineR > arr[i].first){

            maxlen += (arr[i].second - lineR);
            lineR = arr[i].second;

        }
        else if(lineR >= arr[i].second){

            
            continue;

        }

        else{

            lineR = arr[i].second;
            maxlen += (arr[i].second - arr[i].first);
            
        }

    }
    cout<<maxlen<<'\n';
    return 0;
}