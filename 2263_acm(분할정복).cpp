#include<iostream>

int inorder[100001];
int postorder[100001];
int preorder[100001];

using namespace std;

void solve(int in_start, int in_end, int po_start, int po_end){ //preorder는 루트노드부터 프린트한다. 
	
	if(in_start>in_end || po_start>po_end) return;
	int root = postorder[po_end];
	int l;
	int ir;
	for(ir=in_start;ir<=in_end;ir++) if(inorder[ir]==root) break;
	 l = ir-in_start;
	cout<<root<<' ';
	solve(in_start,ir-1,po_start,po_start+l-1);
	solve(ir+1,in_end,po_start+l,po_end-1);
}



int main(){
	
	int V;
	cin>>V;
	for(int i=0;i<V;i++) cin>>inorder[i];
	for(int i=0;i<V;i++) cin>>postorder[i];
	solve(0,V-1,0,V-1);	
	return 0;
}
