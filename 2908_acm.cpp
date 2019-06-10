#include<iostream>
using namespace std;
int main(){
	
	int n,m;
	cin>>n>>m;
	n = (n/100)+((n-100*(n/100))/10)*10 + (n%10)*100;
	m = (m/100)+((m-100*(m/100))/10)*10 + (m%10)*100;
	cout<<(n>=m?n:m)<<'\n';
	
	return 0;
}
