#include<bits/stdc++.h>
#define MOD 100003LL

using namespace std;

typedef long long ll;
ll arr[500002], node_arr[500002];
vector<ll> node[1550000];


ll n,q,x,l0,r0;
ll c=0;

ll minus_mod(ll k, ll m){
  if(k-m<0) return (k+10*MOD-m)%MOD;
  return (k-m)%MOD;
}

ll function_(int num, ll inn){
  if(num&1LL){
				   return minus_mod((2LL*(inn*inn)%MOD)%MOD,1LL);
  }
  return minus_mod((4LL*(((inn*inn)%MOD)*inn)%MOD)%MOD,(3LL*inn));

}

bool comp(pair<ll,ll> &a, pair<ll,ll> &b){
  return a.first < b.first;
}

struct SegmentTree{

    void init(ll start, ll end, ll node_ind){
      if(start==end){
        node_arr[start] = node_ind;
        return;
      }
      int mid = (start+end)>>1;
      init(start , mid, 2LL*node_ind);
      init(mid+1, end, 2LL*node_ind+1LL);
    }
    void change(ll start, ll end, ll num, ll node_ind, ll i, ll j){
				 if(start>=i&&end<=j){
						 node[node_ind].push_back(num);
						 return;
	     	  }else if(i>end||j<start) return;
					int mid=(start+end)>>1;
					change(start,mid,num,2LL*node_ind,i,j);
					change(mid+1,end,num,2LL*node_ind+1LL,i,j);
     }
		 ll query(ll start, ll end, ll node_ind, ll t){
	        ll ans=arr[t];
				  //int proc = fetch(start,end,node_ind,t);
          int proc = node_arr[t];
					vector<ll> st;
					while(proc>0){
              if(node[proc].size()){
                for(auto&p:node[proc]) st.push_back(p);
                //node[proc].clear();
              }
				      proc>>=1;
      	  }
         if(st.size()) for(auto &p:st) ans = function_(p,ans);
         //arr[t] = ans;
				 return ans%MOD;
     }


};
int main(){

         ios_base::sync_with_stdio(0);
         cin.tie(0);
				 cin>>n>>q;
				 for(int i=1;i<=n;i++)cin>>arr[i];
				 SegmentTree S;
         S.init(1,n,1);
				 for(int i=0;i<q;i++){
				   cin>>x;
					if(x==3){
							cin>>l0;
						  cout<<S.query(1,n,1,l0)<<'\n';
		    	}else{
							cin>>l0>>r0;
							S.change(1,n,x,1,l0,r0);
              c++;
				  }
  }

  return 0;

}
