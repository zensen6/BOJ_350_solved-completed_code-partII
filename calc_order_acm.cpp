#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

typedef long long ll;

int n;
string str;

struct Node {
  string data;
  Node* left;
  Node* right;
  
} nodes[1001];

Node* root = &nodes[1];

void initNode(int num, string data) {
  nodes[num].data = data;
  nodes[num].left = nullptr;
  nodes[num].right = nullptr;
}

double travel(Node* now) {
  if((now->data).compare("+")==0 || (now->data).compare("-")==0 || (now->data).compare("/")==0 || (now->data).compare("*")==0){
      double l = travel(now->left), r = travel(now->right);
      if((now->data).compare("+")==0){
          return l+r;
      }else if((now->data).compare("-")==0){
          return l-r;
      }else if((now->data).compare("/")==0){
          return l/r;
      }else return l*r;
  }else{
      return stoll(now->data);
  }
}

int main(int argc, char** argv) {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int test_case;
  
//  freopen("input.txt", "r", stdin);
  for(test_case = 1; test_case <= 10; ++test_case) {
    cin >> n;
    cin.ignore();
    
    for (int i = 0; i < n; ++i) {
      getline(cin, str);
      vector <string> words;
      stringstream stream(str);
      string word;
      
      while (getline(stream, word, ' ')) {
        words.push_back(word);
      }
      
      if (words.empty()) continue;
      
      initNode(stoi(words[0]), words[1]);
      if(words.size() >= 3) nodes[stoi(words[0])].left = &nodes[stoi(words[2])];
      if(words.size() == 4) nodes[stoi(words[0])].right = &nodes[stoi(words[3])];
    }
    
    cout << "#" << test_case << " ";
    double ans = travel(root);
    cout << ll(ans)<< "\n";
  }
  return 0;
}