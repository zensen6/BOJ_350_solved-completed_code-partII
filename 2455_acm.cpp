#include<iostream>
using namespace std;

int main(){
	
	int sum=0;
	int max=0;
	int x,y;
	for(int i=0;i<4;i++){
		
		cin>>x>>y;
		sum-=x;
		sum+=y;
		if(sum>max) max=sum;
	}
	cout<<max<<'\n';
	return 0;
	
	
}
