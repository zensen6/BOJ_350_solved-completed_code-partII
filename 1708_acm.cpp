#include<bits/stdc++.h>
using namespace std;

int n;
typedef long long ll;
stack<int> st;


struct Point_{
  int x,y,p,q;
  Point_(int x1=0, int y1=0): x(x1),y(y1),p(1),q(0) {}
  bool operator < (const Point_ &O) const{
    if(1LL*q*O.p != 1LL*p*O.q) return 1LL*q*O.p < 1LL*p*O.q;
    if(y != O.y) return y < O.y;
    else return x < O.x;
  }
};

ll ccw(Point_ &f, Point_ &s, Point_ &t){
  return (1LL*(s.x-f.x)*1LL*(t.y-f.y)) - (1LL*(s.y-f.y)*1LL*(t.x-f.x));
}


bool comp(Point_ &a, Point_ &b){
  if(a.y != b.y) return a.y < b.y;
  else return a.x < b.x;
}

vector<Point_> pos;

int main(){

  cin>>n;
  pos=vector<Point_>(n);
  for(int i=0;i<n;i++){
    cin>>pos[i].x>>pos[i].y;
  }
  sort(pos.begin(),pos.end(),comp);
  for(int i=1;i<n;i++){
    pos[i].p = pos[i].x-pos[0].x;
    pos[i].q = pos[i].y-pos[0].y;
  }
  sort(pos.begin(),pos.end());

  st.push(0);
  st.push(1);
  int next=2;
  while(next<n){
    while(st.size()>=2){
      int first = st.top();
      st.pop();
      int second = st.top();
      if(ccw(pos[second],pos[first],pos[next]) > 0){
        st.push(first);
        break;
      }
    }
    st.push(next++);
  }
  cout<<st.size()<<'\n';

  return 0;
}
