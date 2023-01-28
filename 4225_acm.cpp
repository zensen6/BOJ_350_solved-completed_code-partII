#include<bits/stdc++.h>
#define MAX 1000002

using namespace std;

typedef long long ll;

struct Point {
    int x, y;
    int p, q;
    Point(int x1 = 0, int y1 = 0) : x(x1), y(y1), p(1), q(0) {}
};

double func(int x1, int y1, int x2, int y2, int x3, int y3){
  if(x1 == x2) return abs(double(x3) - double(x1));
  if(y1 == y2) return abs(double(y3) - double(y1));
  return abs(double(x3) - (double(x1-x2)/double(y1-y2))*y3 - x1 + (double(x1-x2)/double(y1-y2))*y1)/sqrt(1+(double(x1-x2)/double(y1-y2))*(double(x1-x2)/double(y1-y2)));

}

bool comp1(const Point &A, const Point &B) {
    if (A.y != B.y)
        return A.y < B.y;

    return A.x < B.x;
}
bool comp(const Point &A, const Point &B) {
    if (1LL * A.q * B.p != 1LL * A.p*B.q)
        return 1LL * A.q * B.p < 1LL * A.p*B.q;

    if (A.y != B.y)
        return A.y < B.y;

    return A.x < B.x;
}

ll ccw(const Point &A, const Point &B, const Point &C) {
    return 1LL * (A.x*B.y + B.x*C.y + C.x*A.y - B.x*A.y - C.x*B.y - A.x*C.y);
}

Point p[MAX];

int main() {
    int n;
    int tc = 1;
    while(1){
      scanf("%d", &n);
      if(n==0) break;
      for (int i = 0; i < n; i++) {
          int x, y;
          scanf("%d %d", &x, &y);

          p[i] = Point(x, y);
      }

      sort(p, p + n, comp1);

      for (int i = 1; i < n; i++) {
          p[i].p = p[i].x - p[0].x;
          p[i].q = p[i].y - p[0].y;
      }

      sort(p + 1, p + n, comp);

      stack<int> s;

      s.push(0);
      s.push(1);

      int next = 2;

      while (next < n) {
          while (s.size() >= 2) {
              int first, second;
              second = s.top();
              s.pop();
              first = s.top();

              if (ccw(p[first], p[second], p[next]) > 0) {
                  s.push(second);
                  break;
              }
          }

          s.push(next++);
      }
      double ans = 1000*MAX;
      vector<Point> dot;
      while(!s.empty()){
        dot.push_back(Point(p[s.top()].x,p[s.top()].y));
        s.pop();
      }

      for(int i = 0 ; i < dot.size(); i++){
        double tmp = 0;
        for(int j = 0; j < dot.size(); j++){
          if(j != i && j != i+1){
            tmp = max(func(dot[i].x,dot[i].y,dot[(i+1)%dot.size()].x,dot[(i+1)%dot.size()].y,dot[j].x,dot[j].y), tmp);
          }
        }
          ans = min(ans,tmp);
      }
      printf("Case %d: %.2f\n",tc,ceilf(ans*100)/100);
      tc++;
    }


    return 0;
}
