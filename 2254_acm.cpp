#include<bits/stdc++.h>
using namespace std;

int n, Px, Py, ans=0;

struct Point{
  int x,y,p,q,ind;
  Point(int x1=0, int y1=0, int ind1=0): x(x1), y(y1), p(1), q(0), ind(ind1){}
  bool operator < (const Point& O) const{
    if(1LL*q*O.p != 1LL*p*O.q) return 1LL*q*O.p < 1LL*p*O.q;
    if(y != O.y) return y < O.y;
    return x < O.x;
  }
};


long long ccw(Point &f, Point &s, Point &n){
  return(1LL*(s.x-f.x)*(n.y-f.y)) - (1LL*(s.y-f.y)*(n.x-f.x));
}

map<int,int> m;

bool comp(Point &a, Point &b){
  if(a.y != b.y) return a.y < b.y;
  return a.x < b.x;
}

vector<Point> pos;
stack<int> st;


int main(){

  cin>>n>>Px>>Py;
  pos = vector<Point> (n+1);
  pos[0].x=Px,pos[0].y=Py,pos[0].ind=0;
  for(int i=1;i<=n;i++){
    cin>>pos[i].x>>pos[i].y;
    pos[i].ind=i;
  }
  while(1){
    vector<Point> po;
    bool done=false;
    for(auto &p: pos){
      if(!m[p.ind]) po.push_back(p);
      else if(p.ind==0 && m[0]){
        done=true;
        break;
      }
    }
    if(done) break;
    int len=po.size();
    if(len<=3) break;
    sort(po.begin(),po.end(),comp);
    for(int i=1;i<len;i++){
      po[i].p=po[i].x-po[0].x;
      po[i].q=po[i].y-po[0].y;
    }
    sort(po.begin(),po.end());
    st.push(0);
    st.push(1);
    int next=2;
    while(next<len){
      while(st.size()>=2){
        int first = st.top();
        st.pop();
        int second = st.top();
        if(ccw(po[second],po[first],po[next]) > 0){
          st.push(first);
          break;
        }
      }
      st.push(next++);
    }
    while(!st.empty()){
      int t=st.top();
      st.pop();
      if(po[t].ind==0){
        cout<<ans<<'\n';
        return 0;
      }
      m[po[t].ind]=1;
    }
    ans++;
  }
  cout<<ans<<'\n';




  return 0;
}
