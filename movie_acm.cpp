#include<bits/stdc++.h>
using namespace std;

int main() {
   vector<string> movie; //문자열 벡터 생성
   string name;
   int x;


   cout << "<실행방법>" << endl;
   while (1)
   {
      cout << "입력:1, 목록:2, 삭제:3, 종료:4 >>";
      cin >> x;
      if (x == 1) { //영화입력받음
         cout << "영화제목 입력>>";
         cin>>name;
         movie.push_back(name); //영화제목 한개 입력받음

      }
      else if (x == 2) { //이름순으로 출력

         if(movie.size()){
           sort(movie.begin(),movie.end(),[](string &a, string &b){return a.compare(b) > 0? 0:1;});
           for(auto &p: movie) cout<<p<<" ";
           cout<<'\n';
         }
      }
      else if (x == 3) { //입력받을 영화를 지움
         if(!movie.size()){
           cout<<"No movies to delete"<<'\n';
           continue;
         }
         cout << "삭제할 영화제목>>";
         cin >> name;
         vector<string>::iterator it;//이터레이터 생성
         it = movie.begin(); //it의 초기값
         for(; it != movie.end(); ++it){
           if(!name.compare(*it)) movie.erase(it);
         }
      }
      else if (x == 4) { //종료
         cout << "프로그램을 종료합니다.";
         break; //종료
      }
      else{
        cout<<"press other keys"<<'\n';
      }
   }
}
