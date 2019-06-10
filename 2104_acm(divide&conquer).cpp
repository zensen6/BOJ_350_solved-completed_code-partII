#include<iostream>
#include<algorithm>

using namespace std;

long long A[100001];

long long min(long long a, long long b){
	
	
	return a<=b? a:b;
	
}

long long max(long long a, long long b){
	
	
	return a>=b? a:b;
	
}

long long divideconq(int start, int end){ //[start, end)

	if(start ==end)	return 0;
	if(start+1 == end) return A[start]*A[start];
	
	long long mid = (start+end)/2;
	long long ans = max(divideconq(start,mid),divideconq(mid,end));
	
	long w=A[mid],h=A[mid],l=mid,r=mid;
	while(r-l+1<end-start){
		
		int leftvalue = l>start? min(h,A[l-1]) : -1;
		int rightvalue = r<end-1? min(h,A[r+1]) : -1;
		
		if(leftvalue>=rightvalue){
			
			h = leftvalue;
			l--;
			w+=A[l];
		}
		else{
			
			h = rightvalue;
			r++;
			w+=A[r];
		}
		
		ans = max(ans,w*h);
		
	}
	return ans;
	
}

int main(){
	
	long long ans = 0;
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>A[i];
	cout<<divideconq(0,n)<<'\n';
	
	
	return 0;
}
