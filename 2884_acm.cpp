#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int n, m;
	cin>>n>>m;
	int sum = n*60 + m;
	if(n*60+m < 45){
		
		sum = 60*24 - (45-n*60-m);
		
	}
	else{
		
		sum-=45;
		
	}
		
		n = sum/60;
		m = sum%60;
	cout<<n<<' '<<m<<'\n';
	
}
