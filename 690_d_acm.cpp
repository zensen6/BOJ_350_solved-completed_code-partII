#include<bits/stdc++.h>
using namespace std;
int n,t,k,a[3005],ans,dp[3005],sum,cur;
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		dp[0]=0; sum=0;
		for(k=1;k<=n;k++){
			cin>>a[k]; sum+=a[k];
		}
		for(k=n;k>=1;k--){
			if(sum%k) continue; int c=sum/k;
			dp[k]=k-1; cur=0;
			for(int i=1;i<=n;i++){
				cur+=a[i];
				if(cur==c) cur=0;
			}
			if(cur==0){
				cout<<n-k<<endl;
				break;
			}
		}

	}
}
