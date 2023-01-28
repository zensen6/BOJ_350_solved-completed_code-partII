#include<cstdio>
#include<vector>
#include<memory.h>
#include<algorithm>

using namespace std;

//constexpr size_t MAX_LEN = 50;


char str[52];


struct Trie{
    bool terminal;
    Trie* go[26];
    Trie():terminal(false){
        fill(go,go+26,nullptr);
    }
    ~Trie(){
        for(int i=0;i<26;i++) delete go[i];
    }
    void insert(char *key){
        if(*key == '\0'){
            terminal = true;
            return;
        }
        int next = int(*key - 'a');
        if(!go[next]) go[next] = new Trie;
        go[next]->insert(key+1);
        return;
    }
    bool match(char *key){
        if(terminal&&*key=='\0') return true;
        int next = int(*key -'a');
        if(go[next]) return go[next]->match(key+1);
        else return false;
    }

};


int main()
{
    //freopen("sample_input.txt", "r", stdin);

    // 문자열 같음 => 같은 hash table에 저장 (collision 발생) , collision 발생하면 => 개수 +1
    int T;
    scanf("%d", &T);

    for (int test_case = 1; test_case <= T; test_case++) {

        int n, m;
        scanf("%d %d",&n,&m);
        Trie *root = new Trie();
        for (int i = 0; i < n; i++) {
            scanf("%s",str);
            root->insert(str);
        }
        int ans = 0;
        for (int j = 0; j < m; j++) {
            scanf("%s",str);
            if(root->match(str)){
                ans++;
            }
        }
        delete root;
        printf("#%d %d\n",test_case, ans);
    }
    return 0;
}